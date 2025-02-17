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
  int n; cin >> n;
  multiset<ll> s;
  for (auto i = 0; i < n; ++i) {
    ll x; cin >> x;
    s.insert(x);
  }
  ll ans = 0;
  while(s.size() != 1) {
    if(auto it = s.lower_bound(2 * *s.begin()); it != s.end()) {
      ++ans;
      //cout << *s.begin() <<' '<< *it<<'\n';
      s.erase(it);
      s.erase(s.begin());
    } else break;
  }
  cout << ans <<'\n';
  return 0;
}


