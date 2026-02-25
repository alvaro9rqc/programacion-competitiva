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
  ll N,M; cin >>N>> M;
  map<ll,ll> m;
  for (ll i = 0; i < N; ++i) {
    ll l, r;
    cin >> l >> r;
    m[r] = max(m[r], l);
  }
  ll ans = 0;
  for (ll i = 1; i <= M; ++i) {
    if (m.empty()) {
      ans += (M-i+1)*(M-i+2) / 2;
      break;
    }
    auto it = m.begin();
    ll r=it->first,l=it->second;
    ll d = r -i;
    ans += d;
    while(not m.empty() and m.begin()->second <= i) m.erase(m.begin());

  }
  cout << ans <<'\n';
  return 0;
}


