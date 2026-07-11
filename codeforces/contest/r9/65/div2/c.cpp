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
  vector<pair<ll,bool>> xd(n);
  // for(auto& [x,b]: xd) cin >> x>>b;
  for (auto i = 0; i < n; i++) {ll x;cin>>x;xd[i].first=x;}
  for (auto i = 0; i < n; i++) {ll x;cin>>x;xd[i].second=x;}
  sort(all(xd));
  vl _1(n);
  vector<bool> _2(n);
  for (auto i = 0; i < n; i++) _1[i]=xd[i].first;
  for (auto i = 0; i < n; i++) _2[i]=xd[i].second;
  auto f2 = [&](vl val, vector<bool> brr) {
    ll x = -1;
    for (auto i = 0; i < n; i++) {
      if(brr[i]) {
        if(val[i]>x)x=val[i];
      }
    }
    vl cp;
    for (auto i = 0; i < n; i++) {
      if(x==val[i]) {
        cp.emplace_back(x+k);
        x=-1;
      } else cp.emplace_back(val[i]);
    }
    sort(all(cp));
    // for(auto& i: cp) cout<<i<<' ';
    // cout<<'\n';
    // dbg(val[n/2-1]);
    // dbg(val.back());
    return cp[n/2-1]+cp.back();
  };
  auto f1 = [&](vl val, vector<bool> brr) {
    ll idx = n/2-1;
    ll c = 0,s=0;
    stack<ll> st;
    for (auto j = 0; j < idx; j++) 
      if(brr[j])st.emplace(val[j]);
    ll ans = val[idx];
    for (auto i = idx; i < n-1; i++) {
      if(brr[i])st.emplace(val[i]);
      if(!sz(st))break;
      s+=st.top(); st.pop();
      ++c;
      ll ne = val[i]*c-s;
      if(ne>k)break;
      ans=max(ans,min(val[i]+(k-ne)/c,val[i+1]));
    }
    return ans + val.back();
  };
  cout<<max(f1(_1,_2),f2(_1,_2))<<'\n';
  // cout<<f1(_1,_2)<<'\n';
  // cout<<f2(_1,_2)<<'\n';
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

