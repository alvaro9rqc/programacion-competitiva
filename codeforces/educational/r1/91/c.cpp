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
  int n,k;cin>>n>>k;
  string ans(n,'0');
  string s;cin>>s;
  char op='(',cl=')';
  int l=0,r=n-1;
  vi pr(n+1),su(n+1);
  for (auto i = 1; i < n; i++) 
    pr[i]=pr[i-1]+(s[i-1]==op);
  for (auto i = n-2; i >= 0; i--) 
    su[i]=su[i+1]+(s[i+1]==cl);
  // dbg(s[n-1]);
  // for(auto& i: su) cerr<<i<<' ';
  // cerr<<'\n';
  while(l < r and k) {
    while (s[l]==cl and l<n)++l;
    while (s[r]==op and r>=0)--r;
    if(r<=l) break;
    int nl=su[l]-su[r];
    int nr=pr[r]-pr[l];
    // dbg(l);
    // dbg(su[l]);
    if(nl>nr) {
      ans[l]='1';
      --k;
      ++l;
    } else {
      ans[r]='1';
      --k;
      --r;
    }
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

