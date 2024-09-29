#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const long lim = 65536;
bitset<lim> bs;
vector<long> p;

void sieve() {
  bs.set();
  bs[0]=bs[1]=0;
  for (long i = 2; i < lim; ++i) if (bs[i]) {
    for (long j = i*i; j < lim; j += i) bs[j]=0;
    p.push_back(i);
  }
}

long legendres(long n, long p) {
  long a = 0;
  while (n) a += n /= p;
  return a;
}

int main () {
  ios_base::sync_with_stdio(false);
  sieve();
  long m, n;
  while(cin >>n>>m) {
    if (m == 0) {
      cout << m << " does not divide " << n << "!\n";
      continue;
    }
    if ( m <= n ) {
      cout << m << " divides " << n << "!\n";
      continue;
    }
    long cop = m;
    unordered_map<long, long> map;
    for (long i : p) {
      if (i*i > m) break;
      while (m % i == 0) {
        ++map[i];
        m /= i;
      }
    }
    if (m != 1) map[m]++;
    bool div = true;
    for (auto& [x, e]: map) if (e > legendres(n, x)) {
      div=false;
      break;
    }
    if (div) cout << cop << " divides " << n << "!\n";
    else cout << cop << " does not divide " << n << "!\n";
  }
  return 0;
}


