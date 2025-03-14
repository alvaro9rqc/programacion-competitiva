#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T; cin >> T;
  while (T--) {
    ll N, M; cin >> N >> M;
    unordered_map<ll, ll> points;
    auto maxh = [&] (ll xi, ll r) {
      for(ll x=xi-r; x <= xi+r; ++x) {
        ll y = (ll)(sqrt(r*r - (xi-x)*(xi-x)));
        points[x] = max(points[x], y);
        //cerr << x <<' ' << points[x] <<'\n';
      }
    };
    vll p(N), radios(N);
    for (ll i = 0; i < N; ++i) cin >> p[i];
    for (ll i = 0; i < N; ++i) cin >> radios[i];
    for (ll i = 0; i < N; ++i) maxh(p[i], radios[i]);
    ll ans = 0;
    for(auto& [k,v]: points) {
      //cerr << k <<' '<< v <<'\n';
      ans += ( v<<1 ) + 1;
    }
    cout << ans <<'\n';

  }
}


