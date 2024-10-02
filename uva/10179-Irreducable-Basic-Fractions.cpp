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

int EulerPhi(long n) {
  int ans = n;
  for (int i : p) {
    if (i*i > n) break;
    if (n%i == 0) ans -= ans/i;
    while (n%i == 0)
      n /= i;
  }
  if (n!=1) ans -= ans/n;
  return ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  sieve();
  long n;
  while (cin >> n) {
    if (n == 0) break;
    cout << EulerPhi(n) <<'\n';
  }
  return 0;
}


