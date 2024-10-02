#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

long lcm(unordered_map<long, long>& m) {
  long a = 1;
  bool t = false;
  long d;
  if (m[2] > 0 && m[5] > 0)
  {
    d = min(m[2], m[5]);
    t = true;
    m[2] -= d; m[5] -= d;
  }
  for (auto& [p, v]: m) 
    for (long i = 0; i < v; ++i) {
      a *= p;
      a %= 10;
    }
  if (t){
    m[2] += d; m[5] += d;
  }
  return a;
}

int main () {
  ios_base::sync_with_stdio(false);
  const long L = 1011;
  bitset<L> bs;
  vector<long> primos;
  bs.set();
  bs[0]=bs[1]=0;
  for (long i = 2; i < L; ++i) if (bs[i]) {
    for (long j = i*i; j < L; j+=i) bs[j] = 0;
    primos.push_back(i);
  }
  long max=0; vector<long> in;
  unordered_map<long, long> map;
  long x;
  while (cin >> x) 
  {
    if ( x == 0 ) break;
    if (x > max) max = x;
    in.push_back(x);
    map[x];
  }
  unordered_map<long, long> p;
  if (map.find(1) != map.end()) map[1] = 1;
  for (long i = 2; i <= max; ++i) {
    long lim = i;
    for (long j : primos) {
      if (j * j > lim) break;
      int count = 0;
      if (lim % j == 0) p[j];
      while (lim % j == 0)  {
        ++count;
        lim /=j;
      }
      if (count > p[j]) p[j] = count;
    }
    if (lim != 1 && p[lim] < 1) p[lim] = 1;
    if (map.find(i) != map.end()) map[i] = lcm(p);
  }
  for (long i : in) cout << map[i] << '\n';

  return 0;
}


