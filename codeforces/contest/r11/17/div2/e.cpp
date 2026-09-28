#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using pl = pair<ll,ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

struct pli{ ll a; ll b; int i;};


void solve() {
  ll n, x;cin>>n>>x;
  vector<vector<pl>> ori(n);
  vector<vector<pli>> gan(n);
  int ans = 0;
  int ansr = 1;
  for (auto i = 0; i < n; i++) {
    int m;cin>>m;
    ori[i].resize(m);
    for(auto& p: ori[i]) cin>>p.first;
    for(auto& p: ori[i]) cin>>p.second;
    ll a=0,b=0;
    for (auto j = 0; j < m; j++) {
      auto [na, nb] = ori[i][j];
      if(b<na) a+=na-b, b = nb;
      else b+=nb-na;
      // a+=ori[i][j].first;
      // b+=ori[i][j].second;
      if(a<=b) gan[i].emplace_back(a,b,j),a=0,b=0;
    }
  }
  vi nex(n);
  using tlii= tuple<ll,int,int>;
  priority_queue<tlii,vector<tlii>,greater<tlii>> pq;
  for (auto i = 0; i < n; i++) 
    if(sz(gan[i]))pq.emplace(gan[i][0].a, i, 0);
  while(sz(pq)) {
    auto [a, r, c] = pq.top();pq.pop();
    if(x<a) break;
    x+=-gan[r][c].a+gan[r][c].b;
    if((nex[r]=gan[r][c].i+1) >= ans) {
      if(nex[r] == ans) ansr=min(ansr, r+1);
      else ans=nex[r],ansr=r+1;
    }
    // ans=max(ans, nex[r]=gan[r][c].i+1);
    if(c<sz(gan[r])-1) 
      pq.emplace(gan[r][c+1].a, r, c+1);
  }
  for (auto r = 0; r < n; r++) {
    if(nex[r]==sz(ori[r]))continue;
    auto xd = x;
    for (auto i = nex[r]; 
      i < sz(ori[r]) and xd>=ori[r][i].first;
      xd+=-ori[r][i].first+ori[r][i].second,nex[r]=++i
    );
  
    if(nex[r]==ans)ansr=min(ansr,r+1);
    else if(nex[r]>ans)ans=nex[r],ansr=r+1;
  }
  cout<<ans<<' '<<ansr<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

