#include <bits/stdc++.h> 
using namespace std;
int l (int n) {
  if (n & 1) return l(n-1)+1;
  return (n+1)*n/2;
}
int r (int n) {
  if (n & 1) return n*(n+1)/2;
  return r(n-1)+1;
}
int main () {
  ios_base::sync_with_stdio(false);
  int N, a, b,n;
  while (cin >> N) {
    n = (int)(sqrt(N));
    a = l(n); b = r(n);
    while (!(  (a <= N && N <= b) || ( b <= N && N <= a ) )) {
      a = l(++n); b = r(n);
    }
    if (a < b)
      cout << "TERM " << N << " IS " << n - (N - a) << "/" << N - a + 1 << '\n';
    else 
      cout << "TERM " << N << " IS " << N - b + 1 << "/" << n - (N - b) << '\n';

  }
  return 0;
}


