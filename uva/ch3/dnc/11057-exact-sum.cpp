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
  ll N; 
  while(cin >> N) {
    vll A(N);
    for(auto& e: A) cin >> e;
    ll M; cin >> M;
    sort(A.begin(), A.end());
    ll dif = M;
    ll ans1=0,ans2=0;
    for (auto i = 0; i < N/2+N&1; ++i) {
      ll comp = M-A[i];
      //auto f = *A.end();
      //printf("%lld\n", f);
      auto it = ( --upper_bound(A.begin(), A.end(), comp) );
      ll j = (ll)(it-A.begin());
      auto f = *it;
      if (j!=i and f + A[i] == M and abs(f-A[i]) < dif) {
        dif = abs(f-A[i]);
        ans1=min(f,A[i]);
        ans2=max(f,A[i]);
      }
    }
    printf("Peter should buy books whose prices are %lld and %lld.\n\n", ans1,ans2);
    //cout << ans1<<' ' << ans2 <<'\n';

  }

}


