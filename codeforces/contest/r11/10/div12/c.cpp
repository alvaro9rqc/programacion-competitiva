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

void solve() {
  ll n,k;cin>>n>>k;
  if(k==n) {
    cout<<"yes\n";
    for (auto i = n-1; i >= 0; i--) cout<<i<<' ';
    cout<<'\n';
    return;
  } 
  ll obk=64-__builtin_clzll(k);
  ll obn=64-__builtin_clzll(n);
  if(obk>obn){cout<<"no\n";return;}
  ll kp = n^k;
  vl ans={0},vis(n+2);
  vis[0]=1;
  for (auto i = 1ll; i <= kp; i<<=1) {
    if(!(i&kp))continue;
    if(i>=n){cout<<"no\n";return;}
    ans.emplace_back(i);
    vis[i]=1;
  }
  cout<<"yes\n";
  for (auto i = 0; i < n; i++) 
    if(!vis[i])cout<<i<<' ';
  for(auto& i: ans) cout<<i<<' ';
  cout<<'\n';
  
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

