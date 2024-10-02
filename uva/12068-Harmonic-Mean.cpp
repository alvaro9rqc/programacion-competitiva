#include <bits/stdc++.h> 
using namespace std;
long aaaaaah(long m, long n) {
  if (m < n) swap(m,n);
  long t = 0;
  while ((t= m % n ) != 0) {
    m = n; n = t;
  }
  return n;
}
int main () {
  ios_base::sync_with_stdio(false);
  long N, up, low, m, S;
  cin >>S;
  int cou = 0;
  while(cou++ < S) {
    m=1;
    low = 0;
    cin >> N;
    vector<int> v(N);
    int i=0;
    while(i++<N)
    {
      cin>>v[i-1];
      m *= v[i-1];
    }
    up = m*N;
    for (int j=0; j < N;j++) {
      low += m/v[j];
    }
    long g = aaaaaah(up, low);
    cout << "Case " << cou << ": " << up/g << "/" << low/g << '\n';
  }
  return 0;
}


