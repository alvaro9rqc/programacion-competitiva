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
  ll H, W, X, P, Q;
  cin >> H>> W>> X>> P>> Q;
  --P;--Q;
  vector<vll> g(H, vll(W));
  for(auto& r: g) {
    for(auto& c: r) {
      cin >> c;
    }
  }
  vector<vector<bool>> vis(H, vector<bool>(W, false));
  vis[P][Q] = true;
  priority_queue<tuple<ll,ll,ll>> pq;
  ll sum = 0;
  pq.emplace(-g[P][Q], P,Q);
  int dr[] = {1,-1,0,0};
  int dc[] = {0,0,-1,1};
  auto val = [&](int r, int c) {
    return 0 <= r and r < H and 
      0 <= c and c < W and not vis[r][c];
  };
  while(not pq.empty()) {
    auto [w, r, c] = pq.top(); pq.pop();
    w = -w;
    if (sum and not ( w < sum / X + ( sum % X == 0? 0:1) )) break;
    //cout << w <<' '<<r<<' '<<c<<'\n';
    sum += w;
    for (auto i = 0; i < 4; ++i) {
      int nr=r+dr[i], nc=c+dc[i];
      if (val(nr,nc)) {
        pq.emplace(-g[nr][nc], nr,nc);
        vis[nr][nc] = true;
      }
    }
  }
  cout << sum <<'\n';
  return 0;
}


