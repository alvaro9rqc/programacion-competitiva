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
    int n,m;cin>>n>>m;
    vl a(n+m+1),b(m);
    for (auto i = 0; i < n; i++) {
      ll x;cin>>x;
      ++a[x];
    }
    for(auto& i: b) cin >> i;
    vl div(m+n+1);
    for (auto i = 1; i < m+n+1; i++) {
      if(not a[i]) continue;
      for (auto j = i; j < m+n+1; j+=i) div[j]+=a[i];
    }
    int nd,sd,fd;
    nd=sd=fd=0;
    for(auto& i: b) {
      if(div[i]==n)fd++;
      else if (div[i]==0)nd++;
      else sd++;
    }
    if(sd&1) {
      // Bob
      cout<<(nd>fd?"Bob":"Alice")<<'\n';
    } else {
      cout<<(fd>nd?"Alice":"Bob")<<'\n';
    }
  }
}

