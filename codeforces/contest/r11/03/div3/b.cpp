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
  string s;cin>>s;
  for (auto i = 0; i < n-k; i++) {
    if(s[i]=='1') {
      s[i]='0';
      s[i+k]=(s[i+k]=='0'?'1':'0');
    }
  }
  // dbg(s);
  int z = 0;
  for(auto& c: s) if(c=='0')++z;
  cout<<(z==n?"yes":"no")<<'\n';
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

