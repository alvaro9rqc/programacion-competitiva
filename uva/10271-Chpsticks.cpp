#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int memo[1009][5001];

int a[5001];

int b(int i) {
  return (a[i-1]-a[i-2])*(a[i-1]-a[i-2]);
}

int x(int k, int i) {
  if (k == 0) return 0;
  if (memo[k][i] != -1) return memo[k][i];
  int t = b(i) + x(k-1, i-3);
  if (i - 1 >= k*2) {
    int t2 = x(k, i-1);
    t = (t2 < t)? t2:t;
  }
  return memo[k][i] = t;
}

int main () {
  ios_base::sync_with_stdio(false);
  int T, K, N;
  cin >> T;
  while (T--) {
    cin >> K >> N;
    for (auto i = 0; i < N; ++i) 
      cin >> a[i];
    K+=8;
    for (auto i = 0; i < K+1; ++i) 
      for (auto j = 0; j < N; ++j) 
        memo[i][j] = -1;
    cout << x(K, N-1)<<'\n';
  }
  return 0;
}


