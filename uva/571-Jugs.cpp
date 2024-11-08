#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int a, b, n;
vector<vector<bool>> memo;
vector<string> s;
bool f = false;

void x(int i, int j) {
  //cout << i <<' '<< j << '\n';
  memo[i][j] = true;
  if (j == n) 
  {
    f = true;
    return;
  }
  // las operaciones permitidas;
  if (! memo[a][j]) {
    s.push_back("fill A");
    x(a,j);
    if (f) return;
    s.pop_back();
  }
  int h1, h2;
  if (i + j > b) {
    h2 = b;
    h1 = a - ( b - j );
  } else {
    h2 = i + j;
    h1 = 0;
  }
  if (! memo[h1][h2]) {
    s.push_back("pour A B");
    x(h1,h2);
    if (f) return;
    s.pop_back();
  }
  if (! memo[0][j]) {
    s.push_back("empty A");
    x(0,j);
    if (f) return;
    s.pop_back();
  }
  if (i + j > a) {
    h1 = a;
    h2 = b- ( a - i );
  } else {
    h1 = i+j;
    h2 = 0;
  }
  if (! memo[h1][h2]) {
    s.push_back("pour B A");
    x(h1,h2);
    if (f) return;
    s.pop_back();
  }
  if (! memo[i][0]) {
    s.push_back("empty B");
    x(i,0);
    if (f) return;
    s.pop_back();
  }
  if (! memo[i][b]) {
    s.push_back("fill B");
    x(i,b);
    if (f) return;
    s.pop_back();
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  while(cin >> a >> b >> n) {
    f = false;
    s.clear();
    memo.assign(a+1, vector<bool>(b+1, false));
    x(0,0);
    for(auto& str: s) {
      cout << str << '\n';
    }
    cout << "success\n";
  }
  return 0;
}


