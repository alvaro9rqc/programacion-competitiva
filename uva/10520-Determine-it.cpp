#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vector<long>> memo;
int n;
const int NON = -1000;

long a(int i, int j) {
  if (i > n || j > n || i < 0 || j < 0) cout << "Oh no: " << i << ' ' << j <<'\n';
  if (memo[i][j] != NON) return memo[i][j];
  if (i < j) {
    long sum = 0;
    for (auto k = i; k < j; ++k) {
      long t= a(i,k) + a(k+1, j);
      if (t > sum) sum = t;
    }
    return memo[i][j] = sum;
  } else {
    long sum = 0;
    if (j > 0) {
      for (auto k = 1; k < j; ++k) {
        long t = a(i,k) + a(n,k);
        if (t > sum) sum = t;
      }
    }
    long r = 0;
    if (i < n) {
      for (auto k = i+1; k <= n; ++k) {
        long t = a(k,1) + a(k,j);
        if (t > r) r = t;
      }
    }
    return memo[i][j] = sum + r;
  }
}


int main () {
  ios_base::sync_with_stdio(false);
  while (cin >> n) {
    memo.assign(n+1, vector<long>(n+1, NON));
    cin >> memo[n][1];
    cout << a(1,n)<<'\n';
  }
  return 0;
}


