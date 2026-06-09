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
  ll n;cin>>n;
  vl ans(4*n);
  // for (auto i = 0,j=1; i < 2*n; i+=2,++j) {
  //   ans[i]=j;
  //   ans[i+1]=j;
  // }
  // for (auto i = 0,j=1; i < n; i++,++j) {
  //   ans[2*n+i]=j;
  //   ans[3*n+i]=j;
  // }
  if(n==2) {
    ans={2,1,2,2,1,1,2,1};
  }else{
    ll i1=0,i2=0,i3=1,i4=3%n;
    for (auto j = 0; j < n; j++) {
      ans[0*n+i1]=j+1;
      ans[1*n+i2]=j+1;
      ans[2*n+i3]=j+1;
      ans[3*n+i4]=j+1;
      i1=(i1+1)%n;
      i2=(i2+1)%n;
      i3=(i3+1)%n;
      i4=(i4+1)%n;
    }
  }
  for(auto& i: ans) cout<<i<<' ';
  cout<<'\n';
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

