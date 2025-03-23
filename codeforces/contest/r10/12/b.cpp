#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto i = 0; i < n; ++i) {
      cin >> g[i];
    }
    vi accr(n+1,true);
    vi accc(m+1,true);
    bool posi = true;
    for (auto r = 0; r < n; ++r) {
      for (auto c = 0; c < m; ++c) {
        if( g[r][c] == '1' ) {
          if (not (accc[c] ) and (not accr[r] ) ) {
            //cout << accc[c]<< ' '<<c<<'\n';
            //cout << accr[r]<< ' '<<r<<'\n';
            posi=false;
            break;
          }
        } else {
          accc[c]=false;
          accr[r]=false;
        }
        //accc[c+1]+= accc[c];
        //accr[r+1]+= accr[r];

      }
      if (! posi) break;
    }
    if (posi) cout << "YES\n";
    else cout << "NO\n";
  }
}


