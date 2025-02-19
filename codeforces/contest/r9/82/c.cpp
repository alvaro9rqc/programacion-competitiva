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
  while(t--) {
    map<ll, vll>  m;
    ll n; cin >> n;
    for (auto i = 1; i <= n; ++i) {
      ll a;
      cin >> a;
      if ( a - 1 + i >= n ) 
        m[a-1+i].push_back(i-1);
    }
    ll ans = n;
    queue<ll> q;
    q.push(n);
    set<ll> s;
    while(not q.empty()) {
      ll v = q.front(); q.pop();
      if (m.find(v) == m.end()) continue;
      auto& l = m[v];
      for(auto& e: l) {
      //cout <<": "<< v+e <<'\n';
        if(s.find(v+e) == s.end()) {
          q.push(v+e);
          ans = max(ans, v+e);
          s.insert(v+e);
        }
      }
      m.erase(v);
    }
    cout << ans <<'\n';
  }
  return 0;
}


