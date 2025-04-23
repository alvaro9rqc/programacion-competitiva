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
  int t; cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    vll a(n);
    for(auto& e: a) cin >> e;
    auto f = [&](ll v) {
      set<ll> s;
      int g = 0;
      for(auto& e: a) {
        if (e < v) s.insert(e);
        if (ll( s.size() ) == v) {
          ++g; s.clear();
        }
      }
      return g >= k;
    };
    int l = 0, r=n;
    while (l < r){
      int m = l+r;
      if (m &1) m = m/2+1;
      else m /=2;
      if (f(m)) l = m;
      else r = m-1;
    }
    cout << l << '\n';
  }
}


