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
  ll N, M; cin >> N >> M;
  vll P(N);
  for(auto& e: P) {
    cin >> e;
  }
  sort(P.begin(), P.end());
  set<tuple<ll,ll,ll>> s;
  ll ans = 0;
  ll acc = 0;
  s.emplace(P[0], 0, 1);
  while(true) {
    auto [p, idx, h] = *s.begin(); s.erase(s.begin());
    cout << p <<' ' << idx << ' ' << h << '\n';
    if (M - acc < p) break;
    acc += p;
    ans ++;
    s.emplace(P[idx] * (2*h+1), idx, h+1);
    if (h == 1 and idx < N -1) {
      s.emplace(P[idx+1], idx+1,1);
    }
  }
  for(auto& e: P) {
    cout << e <<' ';
  }
  cout <<'\n';
  cout << ans << '\n';
  return 0;
}


