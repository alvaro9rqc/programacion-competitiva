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

ll c_p(ll i, ll j){
  return i - j - 1;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n, q; cin >> n >> q;
    vll X(n); 
    for(auto& e: X) cin >> e;
    unordered_map<ll,ll> m;
    m[n-1]+=1;
    ll ant=n-1;
    for (ll i = 1; i < n; ++i) {
      m[ant]+=c_p(X[i],X[i-1]);
      ant+=n-i-1;
      m[ant]+=1;
      ant-=i;
    }
    for (ll i = 0; i < q; ++i) {
      ll x; cin >> x;
      cout << m[x] << ' ';
    }
    cout << '\n';
  }
}
