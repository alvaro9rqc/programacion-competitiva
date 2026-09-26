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

ll ssp=8;
ll prr[] = {
  0b0000,
  0b0011,
  0b0101,
  0b1001,
  0b0110,
  0b1010,
  0b1100,
  0b1111
};

ll fx(ll x) {
  return x%3==0;
}

void solve() {
  ll n;cin>>n;
  ll que;cin>>que;
  vl arr(n); for(auto& i: arr) cin >> i;
  vector<vl>dpr(ssp,vl(n));
  for (auto i = 0; i < ssp; i++) dpr[i].back()=((arr.back()^prr[i])%3==0);
  for (auto i = n-2; i >= 0; i--) {
    for (auto j = 0; j < ssp; j++) {
      ll x = arr[i]^prr[j];
      ll ans = 0;
      for (auto k = 0; k < ssp; k++) {
        ans=max(ans,fx(x^prr[k])+ dpr[k][i+1]);
      }
      dpr[j][i]=ans;
    }
  }
  vector<vl> dpl(ssp,vl(n));
  for (auto i = 0; i < ssp; i++) 
    dpl[i][0]=fx(arr[0]^prr[i]);
  for (auto i = 1; i < n; i++) {
    for (auto j = 0; j < ssp; j++) {
      ll x = arr[i]^prr[j];
      ll ans = 0;
      for (auto k = 0; k < ssp; k++) {
        ans = max(ans,fx(x^prr[k])+dpl[k][i-1]);
      }
      dpl[j][i]=ans;
    }
  }
  cout<<dpr[0][0]<<' ';
  for (auto _ = 0; _ < que; _++) {
    ll idx,nv;cin>>idx>>nv;
    idx--;
    ll ans= 0;
    if(idx==0) {
      for (auto i = 0; i < ssp; i++) 
        ans= max(ans,fx(nv^prr[i])+dpr[i][1]);
    } else if (idx==n-1) {
      for (auto i = 0; i < ssp; i++) 
        ans=max(ans,fx(nv^prr[i])+dpl[i][n-2]);
    } else {
      for (auto i = 0; i < ssp; i++) {
        for (auto j = 0; j < ssp; j++) {
          ll x = nv^prr[i]^prr[j];
          ans=max(ans,fx(x) + dpl[i][idx-1]+dpr[j][idx+1]);
        }
      }
    }
    cout<<ans<<' ';
  }
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

