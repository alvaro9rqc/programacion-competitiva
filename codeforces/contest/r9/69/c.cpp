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
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    ll n,a,b ; cin >> n>>a >> b;
    ll m = gcd(a,b);
    vl A(n);
    set<ll> s;
    for(auto& e: A) cin >> e, e %= m, s.insert(e);
    ll ans = *(--s.end()) - *s.begin();
    for (auto i = 0u; i < s.size(); ++i) {
      auto c = *s.begin();
      s.erase(s.begin());
      s.insert(c+m);
      ans = min(ans, *(--s.end()) - *s.begin());
    }
    cout << ans << '\n';
  }
}


