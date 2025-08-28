#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

inline ll mand(ll x, ll y, ll px, ll py) {
  ll xd = px-x;
  ll xd2 = py-y;
  if (xd<0)xd=-xd;
  if (xd2<0)xd2=-xd2;
  return xd+xd2;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vector<pair<ll,ll>> pts(n);
    for(auto& [x,y]: pts) cin >> x >> y;
    int pup=0, pdo=0;
    ll xd = ll(5e9);
    ll prx = ll(1e9);
    ll pry = ll(1e9);
    for (auto i = 0; i < n; i++) {
      auto [x,y] = pts[i];
      ll d = mand(x,y, prx, pry);
      if (d < xd) {
        xd = d;
        pup = i;
      }
    }
    xd = ll(5e9);
    prx = ll(1e9);
    pry = -ll(1e9);    
    for (auto i = 0; i < n; i++) {
      auto [x,y] = pts[i];
      ll d = mand(x,y, prx, pry);
      if (d < xd) {
        xd = d;
        pdo = i;
      }
    }
    ll k = ll(1e9);
    cout << "? R " << k << endl; 
    cin >>xd;
    cout << "? R " << k << endl; 
    cin >>xd;
    cout << "? U " << k << endl; 
    cin >>xd;
    cout << "? U " << k << endl; 
    ll s1; cin >> s1;
    cout << "? D " << k << endl; 
    cin >>xd;
    cout << "? D " << k << endl; 
    cin >>xd;
    cout << "? D " << k << endl; 
    cin >>xd;
    cout << "? D " << k << endl; 
    ll s2 ; cin >> s2;
    ll p1x=pts[pup].first;
    ll p2x=pts[pdo].first;
    ll p1y=pts[pup].second;
    ll p2y=pts[pdo].second;
    ll dy = (s1-s2+p1x-p2x+p1y+p2y+4*k)/2;
    ll dx = s1 +p1y-dy+p1x;
    cout << "! " <<(dx-2*k) << " " << (dy-2*k) <<endl;
  }
}


