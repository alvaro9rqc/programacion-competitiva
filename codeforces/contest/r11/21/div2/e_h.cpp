#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

ll N=300000;
ll mod = 998244353;
struct Ti{
  ll y, v;
};

vector<vector<Ti>> bk(N+1);
vl p(N+1,1);
vl be(N+1);

void previo() {
  for (auto i = 2ll; i < N+1; i++) 
    if(p[i]==1) for (auto j = i; j < N+1; j+=i) 
      p[j]*=i;
  for (auto i = 1; i < N+1; i++) bk[i].emplace_back(i,i);
  for (auto y = 2; y < N+1; y++) {
    auto py = p[y];
    for (auto x = py; x < y; x+=py) 
      bk[x].emplace_back(y,-1);
  }
  for (auto x = 2ll,yi=0ll; x < N+1; x++,yi=0) {
    for (auto j = 1ll,xi=x-1; j < sz(bk[x]); j++) {
      while(yi<sz(bk[xi]) and bk[xi][yi].y<bk[x][j].y)
        ++yi;
      bk[x][j].v=bk[xi][yi-1].v;
    }
  }
  be[0]=1;
  for (auto i = 1ll; i < N+1; i++) be[i]=(be[i-1]<<1)%mod;
}

void solve() {
  ll n;cin>>n;
  vl ps(n+2);
  for (auto i = 0; i < n; i++) {
    ll x;cin>>x;
    ++ps[x+1];
  }
  for (auto i = 1; i < n+2; i++) 
    ps[i]+=ps[i-1];
  ll ans = 0;
  for (auto x = 1ll; x < n+1; x++) {
    ll cx = ps[x+1]-ps[x];
    if(!cx)continue;
    //base entre x y el primero
    ans+= be[ps[
      sz(bk[x])==1?n+1:min(bk[x][1].y,n+1)
      ]-ps[x+1]]*(be[cx]-1)%mod*x%mod;
    ans%=mod;
    for (auto j = 1; j < sz(bk[x]) and bk[x][j].y<n+1; j++) {
      ll r = (j==sz(bk[x])-1 or bk[x][j+1].y>n)?n+1:bk[x][j+1].y;
      ll cy = ps[r] - ps[bk[x][j].y];
      ll mid = ps[bk[x][j].y] - ps[x+1];
      ans+=(be[cx]-1)*(be[cy]-1)%mod*be[mid]%mod*bk[x][j].v%mod;
      ans%=mod;
    }
  }
  cout<<ans<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  previo();
  while(tt--) {
    solve();
  }
}

