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
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    int ox, oy, fx, fy;
    cin >> ox >> oy;
    fx = ox + m;
    fy = oy + m;
    for (auto i = 1; i < n; ++i) {
      int x, y; cin >> x >> y;
      fx += x;
      fy += y;
    }
    cout << 2*(fx - ox) + 2*(fy-oy) <<'\n';
  }
}


