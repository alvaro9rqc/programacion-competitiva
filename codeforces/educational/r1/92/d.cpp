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
  string a, b;cin>>a>>b;
  for(auto& c: a) c-='0';
  for(auto& c: b) c-='0';
  int n=sz(a),m=sz(b);
  vl now(m+1), pre(m+1);
  vl pa(n),pb(m);
  pa[0]=a[0];
  pb[0]=b[0];
  for (auto i = 1; i < n; i++) pa[i]=(a[i]+pa[i-1])%10;
  for (auto i = 1; i < m; i++) pb[i]=(b[i]+pb[i-1])%10;
  if(pa.back()!=pb.back()) {
    // dbg(pa.back());
    // dbg(pb.back());
    cout<<"-1\n";
    return;
  }
  for (auto i = 0; i < n; i++) {
    swap(pre,now);
    auto p = pa[i];
    for (auto j = 0; j < m; j++) {
      if(p == pb[j]) {
        now[j+1]=pre[j]+1;
      } else {
        now[j+1]=now[j];
      }
      now[j+1]=max(now[j+1],pre[j+1]);
    }
  }
  cout<<now.back()<<'\n';
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

