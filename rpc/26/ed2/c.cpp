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

vi fuw(string& p, int w, int h) {
  int r=h,c=w;
  int n=w+h-1;
  vi uw(n);
  uw.back()=0;
  for (auto i = n-2; i >= 0; i--) {
    if(p[i]=='R' and r!=1)uw[i]+=1;
    uw[i]+=uw[i+1];
    if(p[i]=='R') c--;
    else r--;
  }
  assert(r==1 and c==1 and "fuw");
  return uw;
}

vi frw(string& p, int w, int h) {
  int r = 1, c = 1;
  vi rw={0};
  for (auto i = 0; i < sz(p); i++) {
    int d = 0;
    if(p[i]=='D' and c!=w) d+=1;
    rw.emplace_back(rw.back()+d);
    if(p[i]=='D') ++r;
    else ++c;
  }
  assert(r==h and c==w and "frw");
  return rw;
}

int solve(string& p, int h, int w) {
  auto uw=fuw(p,w,h);
  auto rw=frw(p,w,h);
  // for(auto& i: uw) cout<<i<<' ';
  // cout<<'\n';
  // for(auto& i: rw) cout<<i<<' ';
  // cout<<'\n';
  int ans = 2*(h+w);
  for (auto i = 0; i < sz(uw); i++) {
    ans=min(ans,uw[i]+rw[i]);
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int h,w;cin>>h>>w;
  string p;cin>>p;
  int ans = solve(p,h,w);
  swap(h,w);
  for(auto& i: p) 
  if(i=='D')i='R';
  else i='D';
  ans+=solve(p,h,w);
  cout<<ans<<'\n';
}

