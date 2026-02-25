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

ll const lim = LLONG_MAX;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N; cin >> N;
  vll_p a(N);
  for(auto& [l,r]: a) {
    cin >> l >> r;
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  for (auto it = a.begin(); it < a.end(); ++it) {
    ll_p p = {( *it ).second, lim};
    auto up = upper_bound(a.begin(), a.end(), p);
    ans += up - it - 1; 
  }
  cout << ans <<'\n';
}


