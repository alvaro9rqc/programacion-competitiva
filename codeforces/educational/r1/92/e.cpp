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

string f(ll x) {
  auto s = bitset<64>(x).to_string();
  s.erase(0,s.find_first_not_of('0'));
  return s;
}

void solve() {
  ll l, r, n;cin>>l>>r>>n;
  int lenl=0,lenr=0;
  lenl=64-__builtin_clzll(l);
  lenr=64-__builtin_clzll(r);
  string x;
  string y;
  if(lenl==lenr) {
    int idx = lenl-1;
    x = f(l);
    for (; idx >= 0; idx--) {
      y.push_back((l&1ll<<idx)!=0);
      if((l&1ll<<idx)!=(r&1ll<<idx))break;
    }
    if(idx==0)y.back()++;
    else for (--idx; idx >= 0; idx--) y.push_back(0);
    for(auto& c: y) c+='0';
  } else {
    ll p2r = 1ll<<(lenr-1);
    y = f(p2r);
    ll p2l = 1ll<<(lenr-2);
    if(l<=p2l) 
      x = f(p2l);
    else 
      x = f(l);
  }
  string ans;
  // dbg(x);
  // dbg(y);
  int ix,iy;ix=iy=0;
  while(sz(ans)!=n){
    if(x[ix]==y[iy] and x[ix]=='1') ans.push_back('1');
    else ans.push_back('0');
    ix=(ix+1)%sz(x);
    iy=(iy+1)%sz(y);
  }
  cout<<ans<<'\n';
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

