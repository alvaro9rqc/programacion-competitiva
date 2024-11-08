#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const long LIM = 1200;
vector<long> p;
bitset<LIM> bs;
void sieve() {
  bs.set();
  bs[0]=bs[1]=0;
  for (auto i = 2; i < LIM; ++i) {
    if (bs[i])  {
      for (auto j = i*i; j < LIM; j+=i) {
        bs[j] = 0;
      }
      p.push_back(i);
    }
  }
}

vector<map<pair<int,int>, long>> memo(15);

long x(long n, long k, long i) {
  if (k == 0) return 0;
  if (n < p[i]) return 0;
  if (k == 1 && p[i] == n) return 1;
  if (memo[k].find({n,i}) != memo[k].end()) return memo[k][{n,i}];
  long s = x(n-p[i], k-1, i+1) + x(n, k, i+1);
  return memo[k][{n,i}] = s;
}

int main () {
  ios_base::sync_with_stdio(false);
  sieve();
  long n, k;
  while (cin >> n >> k) {
    if (n == 0 && k == 0) break;
    cout << x(n,k,0) << '\n';
  }
  return 0;
}


