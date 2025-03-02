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
  int N, M;
  while(cin >> N >> M) {
    if (N == 0) break;
    vector<vi> A(N, vi(M));
    for(auto& r: A) 
      for(auto& c: r) cin >> c;
    int Q; cin >> Q;
    while(Q--) {
      int L, U; cin >> L >> U;
      int dist = 0;
      int nl = N, ml = M;
      for (auto r = 0; r < nl; ++r) {
        auto it = lower_bound(A[r].begin(), A[r].begin()+ml, L);
        if(it == A[r].end()) continue;
        int c = (int)(it - A[r].begin());
        for (auto p = dist; r+p < nl and c+p < ml; ++p) {
          if (A[r+p][c+p] > U) {
            //nl = r+p;
            ml = c+p;
            break;
          }
          dist++;
        }
      }
      cout << dist <<'\n';
    }
    cout <<"-\n";
  }
}


