#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

long po(long b, long e) {
  long m = 1;
  for (long i = 0; i < e; ++i) m*=b;
  return m;
}

int main () {
  ios_base::sync_with_stdio(false);
  const long lim = 131072;
  vector<long> p;
  vector<bool> bs(lim, true);
  bs[0]=bs[1]=0;
  for (long i = 2; i < lim; ++i) 
    if (bs[i]) {
      for (long j = i*i; j < lim; j+=i) bs[j]=0;
      p.push_back(i);
    }

  long c, n;
  cin >> c;
  while (c--) {
    cin >> n;
    if (n > 18) 
    {
      cout << "No\n";
      continue;
    }
    if (cin.peek() == ',') cin.ignore();
    n = po(2, n-1) * ( po(2,n)-1 );
    vector<long> fc;
    if (n != 1 ) fc.push_back(1);
    long sq = (long)sqrt(n);
    long m = 1;
    for (auto i : p) {
      if (i > sq) continue;
      while (n % (m*i) == 0) {
        m*=i;
        fc.push_back(m);
        fc.push_back(n/m);
      }
    }
    long sum = 0;
    for (auto i : fc)
    {
      sum += i;
      //cout << i << ' ';
    }
    //cout << '\n';
    cout << ( (sum == n && fc.size() % 2 == 1) ? "Yes\n":"No\n" );
    //cout << 'z'<<'\n';
  }
  return 0;
}


