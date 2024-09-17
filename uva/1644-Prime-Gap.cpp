#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int lim = 1299710;

int main () {
  ios_base::sync_with_stdio(false);
  bitset<1299710> bs;
  set <int> p;
  bs.set();
  bs[0] = bs[1] = 0;
  for (long i = 2; i < lim; ++i) 
    if (bs[i]) {
      for (long j = i*i; j < lim; j+=i) bs[j] = 0;
      p.insert(i);
    }
  int n; 
  while (cin >> n) {
    if (n == 0) break;
    auto it = p.lower_bound(n);
    if (*it == n) cout << 0 << '\n';
    //else cout << *it << '\n';
    else cout << *it - *--it << '\n';
  }
  return 0;
}


