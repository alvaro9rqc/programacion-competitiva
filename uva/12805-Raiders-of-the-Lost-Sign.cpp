#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int lim = 1010;
bitset<lim> bs;
vii p;
void sieve () {
  bs.set();
  bs[0]=bs[1];
  for (int i = 2; i < lim; i++) if (bs[i]) {
    for (int j = i*i; j < lim; j+= i) bs[j]=0;
    p.emplace_back(i, (i % 4 == 1)? -1:1);
  }

}

int main () {
  ios_base::sync_with_stdio(false);
  sieve();
  int t; cin >> t;
  while (t--) {
    int i; cin >>i;
    int v = 1;
    for (auto& [x, y]:p) {
      //cout << x << '\n';
      if (x*x > i) break;
      //if (i % x == 0) {
      //  v *= y;
      //  while (i % x == 0) i /= x;
      //}
      while (i % x == 0) {
        i/=x;
        v*=y;
      }
    }
    if (i != 1) 
    {
      v *= (i % 4 == 1)? -1:1;
    }
    cout << ( (v == 1)? '+':'-' ) << '\n';
  }

  return 0;
}


