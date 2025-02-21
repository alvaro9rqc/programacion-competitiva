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
  ll N, Q; cin >> N >> Q;
  vll a(N+2);
  a[0]= LLONG_MIN;
  a[N+1] = LLONG_MAX;
  for (ll i = 1; i < N+1; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (ll q = 0; q < Q; ++q) {
    ll b, k; cin >> b >> k;
    auto r = upper_bound(a.begin(), a.end(), b);
    auto l = r-1;
    ll ans;
    for (auto i = 0; i < k; ++i) {
      if( abs(b - *l) > abs(*r - b) ) {
        ans = abs(*r -b);
        ++r;
      } else {
        ans = abs(*l -b);
        --l;
      }
    }
    cout << ans <<'\n';
  }
}


