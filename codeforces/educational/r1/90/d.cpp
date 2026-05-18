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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n;cin>>n;
    vl arr(n), brr(n);
    for(auto& i: arr) cin >> i;
    for(auto& i: brr) cin >> i;
    vl ma(n+1,n),mb(n+1,n);
    vl oa(n,n),ob(n,n);
    vl ja(n),jb(n);
    auto f1 =[&](vl& v, vl& m, vl& j, vl& o) {
      for (auto i = n-1; i >= 0; i--) {
        if(v[i]==n) j[i]=n;
        else j[i]=m[v[i]+1];
        if(v[i]==1)o[i]=i;
        else if(i!=n-1)o[i]=o[i+1];
        m[v[i]]=i;
      }
    };
    f1(arr,ma,ja,oa);
    f1(brr,mb,jb,ob);
    vl dp(n+1);//tiene prefijo
    dp.back()=0;
    for (auto i = n-1; i >= 0; i--) {
      if(arr[i]!=brr[i])continue;
      auto j1=ja[i],j2=jb[i];
      if(j1==j2)dp[i]=j1-i +dp[j1];
      else dp[i]=min(j1,j2) - i;
    }

    ll ans = 0;
    for (auto i = n-1; i >= 0; i--) {
      if(brr[i]!=arr[i] and (brr[i]==1 or arr[i]==1))continue;
      ll j1,j2;
      if(arr[i]!=1) j1=oa[i],j2=ob[i];
      else j1=ja[i],j2=jb[i];
      if(j1!=j2) ans+=min(j1,j2)-i;
      else ans+=j1-i+dp[j1];
    }
    cout<<ans<<'\n';
  }
}

