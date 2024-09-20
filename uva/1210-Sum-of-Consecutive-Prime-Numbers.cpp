#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  int lim = 10000;
  bitset<10001> bs;
  bs.set();
  bs[0]=bs[1]=0;
  vector<int>p;
  for (int i = 2; i <= lim; ++i)
    if (bs[i]) {
      for(int j = i*i; j <= lim; j+=i) bs[j]=0;
      p.push_back(i);
    }
  int n;
  while (cin >> n) {
    if (n == 0) break;
    auto it = upper_bound(p.begin(), p.end(), n/2);
    //--it;
    int count = 0;
    if (bs[n] && n != 2)  ++count;
    for (it; it >= p.begin();--it) {
      int sum = *it;
      for (auto jt = it -1; jt >= p.begin(); --jt) {
        sum += *jt;
        if (sum >= n) break;
      }
      if (sum == n)++count;
      else if (sum < n) break;
    }
    cout << count << '\n';
  }
  return 0;
}


