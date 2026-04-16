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
    vi p1(n),pos(n),p2(n);
    for (auto i = 0; i < n; i++) {
      int x;cin>>x;--x;
      p1[i]=x;
      pos[x]=i;
    }
    for(auto& i: p2) cin>>i,--i;
    vi cic;
    for (auto i = 0; i < n; i++) {
      if(p1[i]==-1) continue;
      int j = pos[p2[i]];
      int len = 1;
      p1[i]=-1;
      while(p1[j]!=-1) {
        ++len;
        p1[j]=-1;
        j=pos[p2[j]];
      }
      cic.emplace_back(len);
    }
    set<int> ose;
    for (auto i = 1; i < n+1; i++) ose.emplace(i);
    sort(cic.rbegin(), cic.rend());
    ll ans = 0;
    for(auto& s: cic) {
      if(s==1)continue;
      vi a,b;
      while((sz(a)+sz(b))<s) {
        auto it1=ose.begin();
        auto it2=ose.end(); --it2;
        a.emplace_back(*it1);
        b.emplace_back(*it2);
        if(sz(a)&1) swap(a.back(),b.back());
        if(it1!=it2)
          ose.erase(it2);
        ose.erase(it1);
      }
      for (auto i = 1; i < sz(a); i++) 
        ans+=abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
      ans+=abs(a.front()-b.front()) + abs(a.back()-b.back());
    }
    cout<<ans<<'\n';
  }
}

