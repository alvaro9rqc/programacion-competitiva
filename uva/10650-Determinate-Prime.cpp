#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  bitset<32001> bs;
  bs.set();
  vi p;
  vi m(32002);
  bs[0] = bs[1] = 0;
  for (long i = 2; i < 32001; ++i)
    if ( bs[i] ) {
      for (long j = i*i; j < 32001; j+=i) bs[j] = 0;
      p.emplace_back(i);
      m[i] = 0;
    }
  for(int i = 0; i+1 < p.size(); ++i) {
    if (! m[ p[i] ]) {
      int dif = p[i+1] - p[i];
      int c = 1;
      for (int j = i+2; j < p.size(); ++j)
        if (p[j] - p[j-1] == dif) 
          c++;
        else break;
      if (c > 1){
        for (int j = i+1; j <= i + c; ++j)
          m[ p[i+1] ] = -1;
        m[ p[i] ] = c;
      }
    }
  }
  int x, y;
  while (cin >> x >> y) {
    if (x == 0 && y == 0) break;
    if (x >y) swap(x,y);
    auto it = lower_bound(p.begin(), p.end(), x);
    if (it  == p.end()) continue;
    for (it; *it < y; it++) {
      //cout << "-- " << x << y << '\n';
      if ( m[ *it ] > 0  ) {
        int alc = m[ *it ] * ( *(it+1) - *it );
        if (( *it + alc ) > y) continue;
        int rep = m [ *it ];
        for (int i = 0; i < rep; ++i)
        {
          cout << *it << ' ';
          it++;
        }
        cout << *it << '\n';
        --it;
      }
    }
  }

  return 0;
}


