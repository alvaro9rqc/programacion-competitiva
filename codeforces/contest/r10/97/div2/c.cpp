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
  char op='(',cl=')';
  while(tt--) {
    int n;cin>>n;
    string a,b;cin>>a>>b;
    int oa,ob,ca,cb;
    oa=ob=ca=cb=0;
    int po=0,pc=0;
    bool can = (a[0]==op and b[0]==op and a.back()==cl and b.back()==cl);
    for(auto& c: a) (c==op)?++oa:++ca;
    for(auto& c: b) (c==op)?++ob:++cb;
    int bal = 0;
    int diffs = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        if (a[i] == op) {
          po++;
          bal++;
        } else {
          pc++;
          bal--;
        }
      } else {
        diffs++;
      }
      if (bal < (diffs % 2)) can = 0;
    }
    can&=( oa+ob==ca+cb and pc==po);
    cout<<(can?"yes":"no")<<'\n';
  }
}

