#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

long memo[66][66];

long x(long n, long s) {
  if (n == 1 && ( s == 1 || s == 0)) return 1;
  if (s > n) return 0;
  if (memo[n][s] != -1) return memo[n][s];
  if (s == 0) {
    long sum = 0;
    for (auto i = 2; i < n; ++i) 
      sum += x(n-i, 0);
    sum += 2;
    return memo[n][s] = sum;
  } 
  long sum = x(n-1, s-1);
  for (auto i = 2; i < n; ++i) {
    if (n-i < s) continue;
    sum += x (n-i, s);
  }
  return memo[n][s] = sum;
}

int main () {
  ios_base::sync_with_stdio(false);
  int n, s;
  for (auto i = 0; i < 66; ++i) 
    for (auto j = 0; j < 66; ++j) 
      memo[i][j] = -1;
  while (cin >> n >> s) {
    if (n < 0 && s < 0) break;
    cout << x(n, s) << '\n';
  }
  return 0;
}


