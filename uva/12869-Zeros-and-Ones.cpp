#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  long l, h;
  while (cin >> l >> h) {
    if (l == 0 and h == 0) break;
    long a = h / 5 - l / 5;
    //cout << ( a + ( (l % 5 == 0)? 1:0 ) )<<'\n';
    cout << a + 1 << '\n';
  }
  return 0;
}


