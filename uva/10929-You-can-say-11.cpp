#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string line;
  while (cin >> line) {
    if (line.size()==1 and line[0]=='0') break;
    int x = (int)(line.back()-'0');
    int ex = 0;
    auto it = --line.end();
    --it;
    while (line.begin() <= it) {
      int c = (int)(*it-- -'0');
      x += ex;
      ex=0;
      if (c < x){
        c+=10;
        ex=1;
      }
      //cout << "-> " << x << '\n';
      x = c - x;
    }
    if (x!=0) cout << line << " is not a multiple of 11.\n";
    else cout << line << " is a multiple of 11.\n";
  }
  return 0;
}


