#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  vector<long> ans(13); 
  vector<long> fac(13); 
  fac[0] = 1;
  long h = 0;
  for (long i = 1; i < ans.size(); ++i) 
  {
    fac[i] = fac[i-1]*i;
    h = h*10 + 1;
    ans[i] = h * fac[i-1];
  }
  long n;
  while ( cin >> n ) {
    if (n == 0) break;
    vector<long> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << accumulate(v.begin(), v.end(), 0L) * ans[n] << '\n';
  }
  return 0;
}


