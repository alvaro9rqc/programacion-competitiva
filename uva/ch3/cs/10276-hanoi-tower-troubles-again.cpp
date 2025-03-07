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

vi g(51,0);
vi ans(51);

bool iss(int n) {
  int r = (int)(sqrt(n));
  return r*r==n;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (auto lim = 1; lim < 51; ++lim) {
    int b = 1;
    fill(g.begin(), g.begin()+lim, 0);
    while(true) {
      bool quit = true;
      for (auto p = 0; p < lim; ++p) {
        if( g[p]==0 or iss(g[p]+b) ) {
          quit = false;
          g[p]=b++;
          break;
        }
      }
      if(quit) break; 
    }
    ans[lim]=--b;
  }
  while(t--) {
    int n; cin >> n;
    cout << ans[n]<<'\n';
  }
}


