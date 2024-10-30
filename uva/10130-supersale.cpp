#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int t, N, G;
vi P(110, 0);
vii A(1010, ii());
int memo[35][1010];

int dp(int w, int idx) {
  if (memo[w][idx] != -1) return memo[w][idx];
  if (idx == 0) return (w < A[idx].first)? 0:A[idx].second;
  if (w < A[idx].first) return memo[w][idx] = dp(w, idx -1);
  return memo[w][idx]= max( A[idx].second + dp(w - A[idx].first, idx -1 ), dp(w, idx -1));
}

int main () {
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t --) {
    memset(memo, -1, sizeof memo);
    cin >> N;
    for (auto i = 0; i < N; ++i) {
      cin >> A[i].second >> A[i].first;
    }
    cin >> G;
    for (auto i = 0; i < G; ++i) {
      cin >> P[i];
    }
    int sum = 0;
    for (int i = 0; i < G; ++i) {
      sum += dp(P[i], N-1);
    }
    cout << sum << '\n';
  }
  return 0;
}


