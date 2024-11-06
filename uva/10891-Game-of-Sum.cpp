#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


long memo[101][101];

long acsum[101];
long sum(long i, long j) {
  return acsum[j+1] - acsum[i];
}

long x(long i, long j) {
  if (memo[i][j] != INT_MIN) return memo[i][j];
  if (i == j) 
    return memo[i][j] = sum(i,i);
  if (i+1 == j) 
    return memo[i][j] = ( sum(i,i) > sum(j,j) )? sum(i,i)-sum(j,j):sum(j,j)-sum(i,i);
  long s = sum(i,j);
  for (auto k = i+1; k <= j; ++k) {
    long t = sum(k, j) - x(i, k-1);
    if (t > s) s = t; 
  }
  for (auto k = j-1; k >= i; --k) {
    long t = sum(i,k) - x(k+1,j);
    if (t > s) s = t;
  }
  return memo[i][j] = s;
}

int main () {
  ios_base::sync_with_stdio(false);
  acsum[0]=0;
  long n;
  while(cin >> n) {
    if (n == 0) break;
    if (n == 1) {
      cin >> n; cout << n << '\n';
      continue;
    }
    if (n == 2) {
      int x, y; cin >>y>>x;
      if (y >= 0 && x >= 0) cout << y + x << '\n';
      else cout << ( (x > y)? x -y:y-x ) << '\n';
      continue;
    }
    for (auto i = 0; i < n; ++i) 
      for (auto j = i; j < n; ++j) 
        memo[i][j]=INT_MIN;
    for (auto i = 1; i <= n; ++i) {
      cin >>acsum[i] ;
      acsum[i] += acsum[i-1];
    }
    cout << x(0, n-1)<<'\n';
  }
  return 0;
}


