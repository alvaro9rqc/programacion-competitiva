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
    vi val(n); for(auto& i: val) cin >> i,--i;  
    vi drr(n);
    int ans = 0;
    int s = 0;
    for (auto i = 0; i < n; i++) {
      s-=drr[i];
      if(val[i]==i)++s;
      else ++s,drr[val[i]]++;
      ans=max(s,ans);
    }
    cout<<s<<'\n';
  }
}

