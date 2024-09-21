#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

map<int, long> m;
bitset<100> bs;
vector<int> p;

void sieve() {
  bs.set();
  bs[0]=bs[1]=0;
  for (int i = 2; i < 100; ++i) 
    if (bs[i]) {
      for (int j = i*i; j < 100; j+=i) bs[j]=0;
      p.push_back(i);
    }
}


void fac(int x, long fx) {
  for (int i : p) {
    if (i*i>x) break;
    if (x % i == 0) {
      m[i];
      int c = 0;
      while (x % i == 0) {
        ++c;
        x /= i;
      }
      m[i] += c * fx;
    }
  }
  if (x != 1) {
    m[x];
    m[x] += fx;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  sieve();
  int f[41];
  f[0]=0;f[1]=1;
  for (int i = 2; i < 41; ++i) {
    f[i] = f[i-1]+f[i-2];
  }
  int t, a, b, n;
  cin >> t;
  f[1]=1;
  while (t--) {
    cin >> n>>a>>b;
    m.clear();
    fac(a, f[n-1]);
    fac(b, f[n]);
    for(auto& [x, v] : m) cout << x << " " << v << '\n'; 
    cout << '\n';
  }
  return 0;
}


