#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const long lim = 100000;
bitset<lim> bs;
vector<long>p;

void sieve() {
  bs.set();
  bs[0]=bs[1]=0;
  for (long i = 2; i < lim; ++i) if (bs[i]) {
    for (long j = i*i; j < lim; j+=i) bs[j]=0;
    p.push_back(i);
  }
}

int numDiv(long n) {
  int ans = 1;
  for (long i : p) {
    if (i*i> n) break;
    int power = 0;
    while (n % i == 0) {
      n /= i; ++power;
    }
    ans *= power+1;
  }
  return (n != 1)? 2*ans:ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  sieve();
  long t; cin >> t;
  while (t--) {
    long x, y;
    cin >> x >> y;
    int nv =0;
    long sel;
    for (long i = x; i <= y; ++i) {
      int t = numDiv(i);
      if (t > nv) {
        sel = i; nv = t;
      }
    }
    cout << "Between " << x << " and " << y << ", "<<sel <<
      " has a maximum of "<< nv <<" divisors.\n";
  }
  return 0;
}


