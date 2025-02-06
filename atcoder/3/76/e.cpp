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
  ll T; cin>>T;
  while(T--) {
    ll N,K; cin >> N>>K;
    vll_p li(N);
    for(auto& [a,b]: li) cin >> a;
    for(auto& [a,b]: li) cin >> b;

    sort(li.begin(),li.end());
    priority_queue<ll> pq;
    ll sum = 0;
    for (ll i = 0; i < K; ++i) {
      pq.emplace(li[i].second);
      sum += li[i].second;
    }
    ll ans = li[K-1].first * sum;
    for (auto i = K; i < N; ++i) {
      auto [a,b] = li[i];
      sum += b;
      pq.emplace(b);
      sum -= pq.top(); pq.pop();
      ans = min(ans, sum* a);

    }
    cout << ans <<'\n';
  }
  return 0;
}


