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
  int n, h, w;cin>>n>>h>>w;
  vector<vector<char>> gri(h,vector<char>());
  int rn=0;
  int ra=-1,rf=0; // rf es antes
  auto next=[&](char xd) {
    if(rn==h or !sz(gri[rn]) )return false;
    gri[rn].emplace_back(xd);
    if(sz(gri[rn])==w) {
      ++rn;
      if(ra!=-1 and ra==rn) {
        if(ra<rf-1 and sz(gri[ra+1]) and gri[ra+1][0]=='A') ++ra;
        else ra=-1;
      }
    } 
    return true;
  };
  ll ans = 0;
  for (auto _ = 0; _ < n; _++) {
    // dbg(ra);
    char ami;cin>>ami;
    if(ami=='I') {
      if(ra!=-1) {
        if(rf!=h) {
          ++ans;
          gri[ra][0]='I';
          ++ra;
          gri[rf].emplace_back('A');
          ++rf;
        } else {
          ++ans;
          gri[ra][0]='I';
          if(ra+1<rf and gri[ra+1][0]=='A')++ra;
          else ra=-1;
          next('A');
        }
      } else {
        if(rf!=h) gri[rf].emplace_back('I'),++rf,++ans;
      }
    } else if(ami=='E') {
      ans+=next('E');
    } else {
      if(rf<h) {
        gri[rf++].emplace_back('A');
        if(rf-1!=0 and ra==-1)ra=rf-1;
        ++ans;
        // dbg(rf);
        // dbg(ra);
      } else {
        ans+=next('A');
      }
    }
  }
  // for(auto& r: gri) {
  //   for(auto& c: r) cout<<c;
  //   cout<<'\n';
  // }
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

