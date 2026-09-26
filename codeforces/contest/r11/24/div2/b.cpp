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

ll nt(ll x) {
  ll r = 0;
  while(x){
    ll o = x%10;
    r+=o*o;
    x/=10;
  }
  return r;
}

void solve() {
  ll n;cin>>n;
  vl arr(n); for(auto& i: arr) cin >> i;  
  vl ite(n);
  ll mite=0;
  for (auto i = 0; i < n; i++) {
    set<ll> ost;
    ll x = arr[i];
    ll c = 0;
    ost.emplace(x);
    while(1) {
      x = nt(x);
      ++c;
      if(ost.count(x))break;
      else ost.emplace(x);
    }
    arr[i]=x;
    ite[i]=c;
    mite=max(mite,c);
  }
  for (auto i = 0; i < n; i++) {
    while(ite[i]<mite) {
      arr[i]=nt(arr[i]);
      ++ite[i];
    }
  }
  map<ll,ll>omp;
  ll ans= 0;
  for (auto i = n-1; i >= 0; i--) {
    ans+=omp[arr[i]]++;
  }
  // for(auto& i: arr) cout<<i<<' ';
  // cout<<'\n';
  cout<<ans<<'\n';
  // raya;
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

