#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const long lim = 100000;
bitset<lim> bs;
vector<long> p;

long gcd(long a, long b) { return b == 0 ? a : gcd(b, a%b); }
long lcm(long a, long b) { return a / gcd(a, b) * b; }

void sieve() {
  bs.set();
  bs[0]=bs[1]=0;
  for (long i = 2; i < lim; ++i) if (bs[i]) {
    for (long j = i*i; j < lim; j += i) 
      bs[j]=0; 
    p.push_back(i);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  sieve();
  int n;
  while (1) {
    cin >> n;
    if ( n == 0 ) break;
    vector<long> fac;
    fac.push_back(1);
    long cp = n;
    for (long i : p) {
      if (i*i > cp) break;
      long s = fac.size();
      long ac = 1;
      while (cp %i == 0) {
        ac *= i;
        for (long j = 0; j < s; ++j) fac.push_back( fac[j]*ac );
        cp /= i;
      }
    }
    if (cp != 1) {
      long s = fac.size();
      long ac = cp;
      for (long j = 0; j < s; ++j) fac.push_back( fac[j]*ac );
    }

    int count = 0;
    //for (long x : fac ) cout << x << ' ';
    for (int i = 0; i < fac.size(); ++i) 
      for (int j = 0; j <= i; ++j) 
        if (lcm(fac[j], fac[i]) == n) ++count;
    cout << n << " "  << count <<  '\n';
  }
  return 0;
}


