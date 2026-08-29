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

const ll lim = ll(2e5+2);
ll op[lim];

void solve() {
  ll n,m;cin>>n>>m;
  vl rrr(m+1);
  vl ss(m+2);
  ll k = 0;
  ll ts = 0;
  for (auto i = 0; i < n; i++) {
    ll x;cin>>x;
    ts+=x;
    ++rrr[x];
    ++ss[x];
    k=max(k, op[x]);
  }
  auto ps = rrr;
  for (auto i = 1; i < m+1; i++) 
    ps[i]+=ps[i-1];
  for (auto i = m; i >= 0; i--) ss[i]+=ss[i+1];
  // dbg(k);
  // dbg(op[4]);
  // dbg(ss[0]);
  vl ans(m+1);
  for (auto i = k; i < m+1; i++) ans[i]=ts;
  for (auto i = 1; i <= m; i++) {
    int ki = 1;
    ll lans = 0;
    ll ac = 0;
    for (auto j = 1; j*i < m+1; j++) {
      ll d =ps[i*j-1]-ps[(j-1)*i];
      ac+=d;
      lans+=(j-1)*d;
      ac+=rrr[i*j];
      lans+=j*rrr[i*j];
      if(i*j==(1<<ki)*i) {
        ans[ki]=max(ans[ki], lans+(n-ac)*( (1<<ki)-1 ));
        ++ki;
      }
      // dbg(ki);
      // dbg(lans);
      // dbg(i);
      // dbg(j);
    }
    if(ki<k) ans[ki]=max(ans[ki], lans);
  }
  for (auto i = 1; i < m+1; i++) cout<<ans[i]<<' ';
  cout<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  op[0]=op[1]=0;
  for (auto i = 2; i < lim; i++) 
    op[i]=1+op[(i+1)/2];
  while(tt--) {
    solve();
  }
}

