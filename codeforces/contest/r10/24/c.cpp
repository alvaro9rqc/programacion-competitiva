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
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;

int dr[] = {0, 1, 0, -1  };
int dc[] = {1, 0, -1, 0};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vector<vi> g(n, vi(n,0));
    int t = 0;
    int r= n/2;
    int c= n/2;
    if (!(n&1)) r--;
    if (!(n&1)) c--;
    int rep = 1;
    int idx = 0;
    while(t < n*n) {
      for (auto i = 0; i < rep; ++i) {
        if (++t >= n*n) break;
        r += dr[idx];
        c += dc[idx];
        g[r][c] = t;
      }
      idx = (idx+1)%4;
      if (!(idx&1)) ++rep;
    }
    for(auto& row: g) 
      for(auto& cel: row) 
        cout << cel << (&cel == &row.back() ? '\n':' ');
  }
}


