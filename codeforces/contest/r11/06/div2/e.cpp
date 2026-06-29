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
  int n;cin>>n;
  string s;cin>>s;
  auto kad=[](int b, int su, int x)->ii {
    su+=x;
    if(su<0)su=0;
    else b=max(b,su);
    return {b,su};
  };
  for(auto& c: s) if(c=='N')c=0;else c=c=='T'?-1:1;
  vector<vi> next(n+1,vi(n+1));
  auto now=next;
  for (auto b = 0; b < n+1; b++) fill(all(now[b]), -b);
  for (auto i = n-1; i >= 0; i--) {
    swap(now,next);
    for (auto b = 0; b <= i; b++) {
      for (auto su = 0; su <= b; su++) {
        int ans = 0;
        if(s[i]) {
          auto [bp,sp]=kad(b,su,s[i]);
          ans=(s[i]==1)+next[bp][sp];
        } else {
          auto [bp1,sp1]=kad(b,su,1);
          auto [bp2,sp2]=kad(b,su,-1);
          ans=max(
            1+next[bp1][sp1],
            next[bp2][sp2]
          );
        }
        now[b][su]=ans;
      }
    }
  }
  cout<<now[0][0]<<'\n';
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

