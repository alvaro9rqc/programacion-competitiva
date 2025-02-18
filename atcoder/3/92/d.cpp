#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
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
  ll N; cin >> N;
  vi K(N);
  vector<unordered_map<ll,ll>> A(N);
  for (auto i = 0; i < N; ++i) {
    cin >> K[i];
    ll xd;
    for (auto j = 0; j < K[i]; ++j) {
      cin >> xd;
      A[i][xd]++;
    }
  }
  double ans = 0;
  for (auto i = 0; i < N-1; ++i) {
    for (auto j = i+1; j < N; ++j) {
      double favor = 0;
      for(auto& [v, c]: A[j]) {
        if(A[i].find(v) != A[i].end()) favor += A[i][v] * c;
      }
      ans = max(ans, favor / (K[i]*K[j]));
    }
  }
  printf("%.12lf\n", ans);
  //cout << ans <<'\n';
  return 0;
}


