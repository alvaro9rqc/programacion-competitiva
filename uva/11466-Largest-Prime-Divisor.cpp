#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  vector<long> p;
  const long lim = 10000010;
  bitset<lim> bs;
  bs.set();
  bs[0]=bs[1]=0;
  for(long i = 2; i <= lim; ++i) {
    if (bs[i] ) {
      for(long j = i*i; j <= lim; j+= i) bs[j] = 0;
      p.push_back(i);
    }
  }
  long n;
  while (cin >> n) {
    if (n == 0) break;
    if (n < 0) n *= -1;
    if (n <= *--p.end() && bs[n]) {
      cout << "-1\n";
      continue;
    }
    long count = 0;
    long cop = n;
    //long root = (long)sqrt(n);
    long div = -1;
    for (long i = 0; i < p.size() && p[i]*p[i] <= n; ++i) {
      if ( n % p[i] == 0 )++count;
      else continue;
      while (n % p[i] == 0) {
        n /= p[i];
        div = p[i];
      }
    }
    if ((cop == n) || ( count < 2 && n == 1 )) cout << "-1\n";
    else cout << ( (n > div)? n: div ) << '\n';
  }
  return 0;
}


