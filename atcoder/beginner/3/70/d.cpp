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
  int H,W,Q; cin >> H >> W >> Q;
  unordered_map<int,set<int>> mr;
  unordered_map<int,set<int>> mc;
  auto f=[&mc, &mr](unordered_map<int,set<int>> & m, int a, int b) {
    //cout << "-> " << a <<' '<<b<<'\n';
    auto& om = &m == &mc ? mr:mc;
    auto x = m[a].upper_bound(b);
    if (x != m[a].begin()) 
    {
      --x;
      //cout << ": " << a <<' ' << *x<<'\n';
      om[*x].erase(a);
      m[a].erase(x);
    }
    auto y = m[a].upper_bound(b);
    //for(auto& e: m[a]) {
    //  cout << e <<' ';
    //} cout <<'\n';
    if (y != m[a].end()) 
    {
      //cout << "; " << a <<' ' << *y<<'\n';
      om[*y].erase(a);
      m[a].erase(y);
    }

  };
  for (auto c = 0; c < W; ++c) 
    mr[0].insert(c);
  for (auto r = 1; r < H; ++r) 
    mr[r]=mr[0];
  for (auto r = 0; r < H; ++r) 
    mc[0].insert(r);
  for (auto c = 1; c < W; ++c) 
    mc[c] = mc[0];
  for (auto i = 0; i < Q; ++i) {
    int r, c; cin >> r >> c;
    --r;--c;
    if (mr[r].find(c) != mr[r].end()) {
      mr[r].erase(c);
      mc[c].erase(r);
    } else {
      f(mr, r,c);
      f(mc, c,r);
    }
  }
  int ans = 0;
  for(auto& [k, m]: mr) {
    ans += m.size();
  }
  cout << ans <<'\n';
  return 0;
}


