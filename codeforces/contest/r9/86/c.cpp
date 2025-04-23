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
    ll n,m,v; cin >> n >> m >> v;
    vll sa(n), a(n);
    for(auto& e: a) cin >> e;
    sa[0]=a[0];
    for (ll i = 1; i < n; ++i) sa[i]= a[i]+sa[i-1];
    stack<ll> st;
    st.push(-1);
    auto clos = [&](ll i, ll j){
      if (i > j) return 0ll;
      if (i == 0) return sa[j];
      return sa[j]-sa[i-1];
    };
    for (ll i = 0; i < n; ++i) {
      ll s = clos(st.top()+1, i);
      if (s >= v) st.push(i);
      if(ll( st.size() )-1 == m) break;
    }
    if (ll( st.size() )-1 != m) { cout << -1 << '\n'; continue; }
    ll right = n;
    ll ans = -1;
    while(1){
      ans = max(ans, clos(st.top()+1, right-1));
      //cerr <<"> "<<st.top()<< ' '<< right << '\n';
      st.pop();
      if (st.size()==0) break;
      for (ll i = right-1;1 ; --i) {
        ll s = clos(i, right-1);
        if (s >= v) {right=i; break;}
      }
    }
    cout << ans << '\n';
  }
}


