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
  int n,m;cin>>n>>m;
  vl val(n); for(auto& i: val) cin >> i;  
  for (auto i = 1; i < n; i++) val[i]+=val[i-1];
  auto pre=[&](int c, int l, int r) {
    return (c?-1:1)*(val[r]-(l?val[l-1]:0));
  };
  vi brr(m); for(auto& i: brr) cin >> i;
  sort(brr.rbegin(), brr.rend());
  vl now = {pre(0,0,brr.back()-1), pre(1,0,brr.back()-1)},nex={0,0};
  now[0]=max(now[0],now[1]);
  now[1]=now[0];
  for (auto i = m-2; i >= 0; i--) {
    swap(now,nex);
    //0
    for (auto b = 0; b < 2; b++) {
      now[b]=max(
        pre(1^b,brr[i+1],brr[i]-1)+nex[b^1],
        pre(b,brr[i+1],brr[i]-1)+nex[b]
      );
    }
  }
  ll xd = 0;
  if(brr[0]!=n) xd=pre(0,brr[0],n-1);
  cout<<(now[0]+xd)<<'\n';
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

