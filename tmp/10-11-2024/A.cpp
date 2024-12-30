#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  int n, x,y, dx, dy, a, b;
  string str;
  int t;
  cin >> t;
  vii delta(11, {0,0});
  while (t --) {
    dx=dy=x = y = 0;
    cin >> n >> a >> b>>ws;
    getline(cin,str);
    for (auto i = 0; i < n; ++i) {
      if (str[i] == 'N') {
        delta[i].first=0;
        delta[i].second=1;
        dy++;
      } else if (str[i] == 'S') {
        delta[i].first=0;
        delta[i].second=-1;
        dy--;
      } else if (str[i] == 'E') {
        delta[i].first=1;
        delta[i].second=0;
        dx++;
      } else if (str[i] == 'W') {
        delta[i].first=-1;
        delta[i].second=0;
        dx--;
      }    
    }
    int rep = 16;
    if (dx == 0 and dy == 0) rep = 1;
    bool f = false;
    for (auto i = 0; i < rep; ++i) {
      for (auto j = 0; j < n; ++j) {
        x+=delta[j].first;
        y+=delta[j].second;
        if (x == a and y == b) {
          f = true;
          goto etiqueta;
        }
      }
    }
etiqueta:
    if (f) cout <<"YES\n";
    else cout << "NO\n";
  }
  return 0;
}


