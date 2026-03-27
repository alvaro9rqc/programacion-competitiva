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
    int n,k;cin>>n>>k;
    vector<string> gri(k);
    const int alf=26;
    string ans;
    for(auto& i: gri)    {
      cin>>i;
      if(not sz(ans))ans=i;
      for(auto& c: i) c-='a';
    }
    for (auto i = 1; i <= n/2; i++) {
      if(n%i!=0)continue;
      int xd = 0;
      string lans;
      for (auto j = 0; j < i; j++) {
        vi l(alf), r(alf,k);
        for (auto c = 0; c < k; c++) ++l[gri[c][j]];
        for (auto e = 2; e*i <= n; e++) {
          vi aux(alf);
          for (auto c = 0; c < k; c++) ++aux[gri[c][(e-1)*i+j]];
          for (auto c = 0; c < alf; c++) r[c]=min(r[c],aux[c]);
        }
        bool can = 0;
        int x=0;
        for (auto c = 0; c < alf and not can; c++) {
          can|=(l[c] and r[c]);
          x=c;
        }
        xd+=can;
        lans.push_back('a'+x);
      }
      if (xd==i) {ans=lans;break;}
    }
    for (auto i = 0; i < n/sz(ans); i++) 
      cout<<ans;
    cout<<'\n';
  }
}

