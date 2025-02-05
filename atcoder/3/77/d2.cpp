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
  ll N,M;cin>>N>>M;
  set<ll>L,R;
  for (ll i = 0; i < N; ++i) {
    int l,r; cin >> l>>r;
    L.insert(l);
    R.insert(r);
  }
  ll ans = 0;
  for(ll i = 1; i<= M; ++i) {
    auto l = L.lower_bound(i);
    if (l == L.end()) 
    {
      ans += (M-i+1)*(M-i+2) / 2;
      break;
    }
    auto r = R.lower_bound(*l);
    ll d1 = *r - i;
    ans += d1;
  }
  cout << ans <<'\n';
  return 0;
}


