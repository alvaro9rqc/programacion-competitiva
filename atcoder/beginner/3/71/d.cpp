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
  ll N, Q;
  cin >> N;
  vll X(N), P(N);
  for(auto& e: X) cin >> e;
  for(auto& e: P) cin >> e;
  cin >> Q;
  map<ll,ll> s;
  s[INT_MIN] = 0;
  auto it = s.begin();
  for (ll i = 0; i < N; ++i) {
    s[X[i]] = it->second + P[i];
    it++;
  }
  for (ll i = 0; i < Q; ++i) {
    ll l, r; cin >> l >> r;
    auto a = --s.lower_bound(l);
    auto b = --s.upper_bound(r);
    cout << b->second - a->second <<'\n';
  }
  return 0;
}


