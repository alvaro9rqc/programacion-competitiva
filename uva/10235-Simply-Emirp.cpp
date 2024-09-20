#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  const long lim = 1000000;
  bitset<lim> bs;
  bs.set();
  vi p;
  bs[0]=bs[1]=0;
  for (long i = 2; i < lim; ++i) 
    if( bs[i] ) {
      for (long j = i*i; j < lim; j+=i) bs[j]=0;
      p.push_back(i);
    }
  int n;
  while (cin >> n) {
    string r = to_string(n);
    reverse(r.begin(), r.end());
    int re = stoi(r);
    if (bs[n]) {
      if (bs[re] && re != n) cout << n << " is emirp.\n";
      else cout << n << " is prime.\n";
    } else cout << n << " is not prime.\n";
  }
  return 0;
}


