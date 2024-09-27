#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b) { return b== 0? a: gcd(b, a%b); }

int main () {
  ios_base::sync_with_stdio(false);
  vi v(501); 
  v[1] = 0;
  int n = 501;
  for (int i = 2; i <= n; ++i) {
    int c = 0;
    for (int j = 1; j < i; ++j) c += gcd(i, j);
    v[i] = v[i-1] + c;
  }
  while (cin >> n) {
    if (n == 0) break;
    cout << v[n] << '\n';
  }
  return 0;
}


