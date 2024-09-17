#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<long> v;
bitset<1000001> bs;


int main () {
  ios_base::sync_with_stdio(false);
  bs.set();
  bs[0] = bs[1] =0;
  long lim = 1000000;
  for (long i = 2; i < lim; ++i) 
    if (bs[i]) {
      for (long j = i*i; j <lim; j+= i )
        bs[j]=0;
      v.push_back(i);
    }
  int n; cin >> n;
  while (n) {
    bool f = false;
    int m = n / 2;
    for (long i : v) {
      if (i > m) break;
      if ( bs[n - i] ) {
        f = true;
        cout << n << " = " << i << " + " << n - i << '\n';
        break;
      }
    }
    if (!f ) cout << "Goldbach's conjecture is wrong.\n";
    cin >> n;
  }
  return 0;
}


