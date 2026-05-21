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
  int n;cin>>n;
  vl val(n); 
  for(auto& i: val) cin >> i; 
  ll nh=val[0],ph=-1;
  // vl id;
  ll d = 0;
  for (auto i = 1; i < n; i++) {
    auto v = val[i];
    if(nh>v) {//peq
      if(ph>v) {cout <<"no\n";return;} //p p
      d=max(d,nh-v);
      ph=v;
    } else nh=v;
  }
  for (auto i = 1; i < n; i++) {
    if(val[i-1]>val[i])val[i]+=d;
    if(val[i-1]>val[i]) {cout<<"no\n";return;}
  }
  cout<<"yes\n";
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

