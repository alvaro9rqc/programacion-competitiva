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

pair<vi,vi> fi(vi& val) {
  stack<ii> sc,sp;
  vi cl(sz(val),-1),pl(sz(val));
  int n = sz(val);
  for (auto i = 0; i < n; i++) {
    //pl
    while(sz(sp) and sp.top().first<val[i]) sp.pop();
    if(sz(sp)) pl[i]=i-sp.top().second-1;
    else pl[i]=i;
    sp.emplace(val[i],i);
    //cl
    if((i and i <n-1)and val[i-1]<val[i] and val[i]>val[i+1]) {
      while(sz(sc) and sc.top().first<val[i]) {
        int d = i-sc.top().second-1;
        if(d<pl[i]) cl[i]=sc.top().second;
        sc.pop();
      }
      sc.emplace(val[i],i);
    }
  }
  return {cl,pl};
}

vi memo;
vi cl,pl,cr,pr;

int dp(int i) {
  if(i<0)return 0;
  if(memo[i]!=-1)return memo[i];
  auto& ans = memo[i];
  ans=min(
    pl[i]+dp(cr[i]),
    pr[i]+dp(cl[i])
  );
  return ans;
}

void solve() {
  int n;cin>>n;
  vi val(n); for(auto& i: val) cin >> i; 
  tie( cl,pl )=fi(val);
  reverse(all(val));
  tie( cr,pr )=fi(val);
  reverse(all(cr));
  reverse(all(pr));
  for(auto& i: cr) if(i!=-1) i=n-i-1;

  // for(auto& i: cl) cout<<i<<' ';
  // cout<<'\n';
  // for(auto& i: pl) cout<<i<<' ';
  // cout<<'\n';
  // for(auto& i: cr) cout<<i<<' ';
  // cout<<'\n';
  // for(auto& i: pr) cout<<i<<' ';
  // cout<<'\n';

  memo.assign(n,-1);
  int xd=1;
  for (auto i = 1; i < n-1; i++) 
    if(val[i-1]<val[i]and val[i]>val[i+1]) {
      xd=i; break;
    }
  for (auto i = 1; i < n-1; i++) {
    if(val[i-1]<val[i]and val[i]>val[i+1] and val[xd]<val[i]) xd=i;
  }
  cout<<dp(n-1-xd)<<'\n';
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


