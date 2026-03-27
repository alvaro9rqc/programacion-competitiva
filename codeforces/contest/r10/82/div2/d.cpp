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
    bool can = 1;
    vi l(n),r,ans;
    iota(all(l),1);
    while(1) {
      can&=n<= k and k <= n*2-1;
      if(not can)break;
      if(k!=n*2-1) {
        ans.emplace_back(l.back());
        ans.emplace_back(l.back());
        l.pop_back();
        k-=1;
        n-=1;
        continue;
      }
      if(n==1) {
        ans.emplace_back(l.back());
        ans.emplace_back(l.back());
      } else {
        ans.emplace_back(l.back());
        r.emplace_back(l.back());
        l.pop_back();
        ans.emplace_back(l.back());
        r.emplace_back(l.back());
        l.pop_back();
        int j = 0;
        for (auto i = 0; i < n-2; i++) {
          ans.emplace_back(l.back());
          r.emplace_back(l.back());
          l.pop_back();
          ans.emplace_back(r[j++]);
        }
        ans.emplace_back(r[j++]);
        ans.emplace_back(r[j++]);
      }
      break;
    }
    cout<<(can?"Yes":"No")<<'\n';
    if(can) {
      for(auto& i: ans) cout<<i<<' ';
      cout<<'\n';
    }
  }
}

