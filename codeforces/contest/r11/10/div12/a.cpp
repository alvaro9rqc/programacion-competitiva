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
  int ans = 0;
  int n,k;cin>>n>>k;
  string s;cin>>s;
  if(k*2>n){
    cout<<"-1\n";
    return;
  }
  for (auto i = 0; i < k; i++) 
    if(s[i]!='R')++ans;
  for (auto i = n-1; i > n-1-k; i--) 
    if(s[i]!='L')++ans;
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

