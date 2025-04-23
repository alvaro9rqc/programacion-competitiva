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
  ll t; cin >> t;
  while(t--){
    ll n; cin >> n;
    vll p(n);
    for(auto& e: p) {
      cin >> e;
      --e;
    }
    ll ans = 0;
    vector<bool> vis(n, false);
    for (ll i = 0; i < n; ++i) {
      ll v; cin >> v;
      --v;
      ll stp = 0;
      while(not vis[v]) {
        ++stp;
        vis[v]=true;
        ll u = p[v];
        p[v]=v;
        v = u;
      }
      ans += stp;
      cout << ans << ' ';
    }
    cout << '\n';
  }
}


