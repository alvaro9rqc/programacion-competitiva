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

int nlim = int(40);
ll lim = ll(1e11+12);
vl p(nlim), sp(nlim), sc(nlim), asc(nlim);
ll mod = ll(1e9+7);


void load() {
  for (auto i = 1; i < nlim; i++) {
    //if (sp[i-1]>lim) sp[i] = sp[i-1], p[i] = p[i-1];
    //else {
      p[i] = 1ll<<(i-1);
      sp[i] = (1ll<<(i))-1;
    //}
  }
  sc[1]=1, asc[1]=1;
  for (auto i = 2; i < nlim; i++) {
    sc[i] = i * asc[i-1];
    sc[i]%=mod;
    asc[i] = sc[i]*asc[i-1];
    asc[i]%=mod;
  }
}

ll lin(ll k) {
  //dbg(k);
  if (k == 0) return 1;
  auto it = --upper_bound(all(sp), k);
  //auto it = --partition_point(all(sp), [&k](ll pun){
  //    return k>=pun;
  //    });
  int i = int(it-sp.begin());
  k-=sp[i];
  if(k==0)return asc[i];
  ll ans = asc[i]*lin(k-1)%mod;
  return ans*(i+1)%mod;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  load();
  //for (auto i = 0; i < 6; i++) {cout<<sp[i]<<' ';}cout<<'\n';
  int tt; cin >> tt;
  while(tt--) {
    int n; ll k;cin >> n >> k;
    vl arr(n);
    for(auto& i: arr) cin>> i;
    sort(all(arr));
    ll ans = 1;
    for (auto& i: arr) {
      if (i >=nlim or p[i]>k){
        ans*=i;
        ans%=mod;
        ans*=lin(k-1);
        ans%=mod;
        break;
      }else{
        k-=p[i];
        ans*=sc[i];
        ans%=mod;
        if (k == 0) break;
      }
    }
    cout << ans <<'\n';

  }
}


