#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  vector<unsigned long> ans(13); 
  vector<unsigned long> fac(13); 
  fac[0] = 1;
  ans[0] = 0;
  for (unsigned long i = 1; i < ans.size(); ++i) 
  {
    fac[i] = fac[i-1]*i;
    ans[i] = ans[i-1]*10+1;
  }
  unsigned long n;
  while ( cin >> n ) {
    if (n == 0) break;
    unsigned long s = 0;
    unsigned long x;
    unordered_map<unsigned long, int> m;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      if (m.find(x) == m.end()) m[x] = 1;
      else m[x]++;
      s += x;
    }
    if (m.size() == 1) cout << x * ans[n] << '\n';
    else {
      unsigned long a = s*fac[n-1];
      for (auto& [ k, v ] : m) a /= fac[v];
      cout << a * ans [n] << '\n';
    }
  }
  return 0;
}


