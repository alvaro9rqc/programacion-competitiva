#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, M, Sx, Sy;
  cin >> N >> M >> Sx >> Sy;
  map<ll,set<ll>> xy;
  map<ll,set<ll>> yx;
  for (ll i = 0; i < N; ++i) {
    ll xx, yy;
    cin >> xx >> yy;
    xy[xx].insert(yy);
    yx[yy].insert(xx);
  }
  ll ans = 0;
  for (ll _ = 0; _ < M; ++_) {
    char D; ll C;
    cin >> D >> C;
    if (D == 'U') {
      auto it = xy[Sx].lower_bound(Sy);
      while(it != xy[Sx].end() and *it <= Sy + C) {
        ans++;
        yx[*it].erase(Sx);
        it=xy[Sx].erase(it);
      }
      Sy += C;
    }
    else if (D == 'D') {
      auto it = xy[Sx].lower_bound(Sy-C);
      while(it != xy[Sx].end() and *it <= Sy) {
        ans++;
        yx[*it].erase(Sx);
        it=xy[Sx].erase(it);
      }
      Sy -= C;
    }
    else if (D == 'R') {
      auto it = yx[Sy].lower_bound(Sx);
      while(it != yx[Sy].end() and *it <= Sx + C) {
        ans++;
        xy[*it].erase(Sy);
        it = yx[Sy].erase(it);
      }
      Sx+=C;
    }
    else if (D == 'L'){
      auto it = yx[Sy].lower_bound(Sx-C);
      while(it != yx[Sy].end() and *it <= Sx) {
        ans++;
        xy[*it].erase(Sy);
        it = yx[Sy].erase(it);
      }
      Sx-=C;
    }
  }
  cout << Sx <<' ' << Sy << ' ' << ans << '\n';
  return 0;
}


