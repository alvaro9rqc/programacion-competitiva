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
    string s(n,'0');
    vi arr(n); for(auto& i: arr) cin>>i;
    vi sup(n), inf(n);
    sup.back()=n-1;
    inf.back()=n-1;
    for (auto i = n-2; i >= 0; i--) {
      if (arr[i]<arr[i+1]) {
        sup[i]=sup[i+1];
        inf[i]=i;
      } else {
        inf[i]=inf[i+1];
        sup[i]=i;
      }
    }
    string x;cin>>x;
    int a =0;
    bool can = 1;
    vector<ii> ans;
    if (x[0]=='1' or x.back()=='1') can=0;
    for (auto i = 1; i < n-1; i++) {
      if (s[i]=='0' and x[i]=='1') {
        if (a++<5) {
          int l = max(sup[i-1], inf[i-1]);
          ans.emplace_back(i, l+1);
          for (auto j = i; j < l; j++) {
            s[i]='1';
          }
        } else{
          can=0;
          break;
        }
      }
    }
    if (can) {
      cout<<sz(ans)<<'\n';
      for(auto& [a,b]: ans) cout<<a<<' '<<b<<'\n';
    } else cout<<"-1\n";
  }
}

