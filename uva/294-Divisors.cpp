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
    for (long j = i*i; j < lim; ++j) bs[j]=0;
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
  return 0;
}


