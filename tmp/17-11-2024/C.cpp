#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const long long LIM = 200100;
bitset<LIM> bs;



int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bs.set();
  bs[0] = bs[1] = 0;
  for (long long i = 2; i < LIM; ++i) {
    if (bs[i]) {
      for (long long j = i*i; j < LIM; j+=i) {
        if (j < 0) continue;
        bs[j] = 0;
      }
    }
  }
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int limp = (n %2 == 0)? n-1:n;
    int f=-1;
    for (int i = 2; i <= n; i+=2) {
      if (i + limp >= LIM) {
        cout << "-1\n";
        return 0;
      }
      if (!bs[i + limp]) {
        f = i; 
        break;
      }
    }
    if (f == -1) {
      cout << f << '\n';
      continue;
    }
    for (int i = 1; i <= n; i+=2) {
      cout << i << ' ';
    }
    cout << f << ' ';
    for (int i = 2; i <= n; i+=2) {
      if (i == f) continue;
      cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
}


