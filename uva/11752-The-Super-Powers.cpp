#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
long long lim = 65537;
long long LIMI =  LONG_LONG_MAX;
vector<long long> p;
vector<long> comp;
set <long long> ans;
bitset<65538>bs;

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  comp.push_back(0);
  for (long i = 2; i < lim; ++i ) 
    if (bs[i]) {
      for (long j = i*i; j < lim; j += i ) {
        bs[j] = 0;
        comp.push_back(j);
      }
      p.push_back(i);
    }
}

long long pot(long long p, long x) {
  long long m = 1;
  for (long i = 1; i <= x; ++i) m*=p;
  return m;
}

//long long pot(long long p, long x) {
//
//}

void backtraking(int i, long long m) {
  if (i >= p.size() || m * 8 > LIMI / 2) {
    return;
  }
  for (auto x : comp) {
    cout << m << " "<<x<< '\n';
    long long y = pot(p[i], x);
    long long v = m * y;
    if (v < m) return;
    //if (m != 1) cout << m << '-'<< '\n';
    if (v < LIMI && v > 0) {
      if (v != 1)
      {
        ans.insert(v);
        //cout << v << '\n';
      }
      if (v * 2 < LIMI && v * p[i] > 0)
        backtraking(i+1, v);
    } else return;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  sieve();
  backtraking(0, 1);
  //for(int i = 0; i < 10; ++i) cout << comp[i] << '\n';
  for (const long long& i:ans) cout << i << '\n';
  return 0;
}


