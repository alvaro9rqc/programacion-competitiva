#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  const long lim = 1l << 16;
  bitset<lim> bs;
  //for (long i = 0; i < lim; ++i) bs[i]=true;
  bs[0]=bs[1]=false;
  bs.set();
  vector<long>p;
  for (long i = 2; i < lim; ++i) 
    if (bs[i]) {
      for (long j = i*i; j < lim; j+= i) bs[j]=false;
      p.push_back(i);
    }
  long n;
  while (cin>>n) {
    if (n == 0) break;
    long cop = n;
    vector<long> fp;
    bool neg = false;
    if (n < 0) {
      neg = true;
      n *=-1;
    }
    for (long pri : p) {
      if (pri * pri > n) break;
      while (n%pri == 0){
        n /= pri;
        fp.push_back(pri);
      }
    }
    if (n != 1) fp.push_back(n);
    cout << cop << " = ";
    if (neg) cout << "-1 x ";
    cout << fp[0];
    for (int i = 1; i < fp.size(); ++i) cout << " x " << fp[i];
    cout << '\n';
  }
  return 0;
}


