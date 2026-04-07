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
    ll k;
    ll n;cin>>n>>k;
    ll s = 0;
    for (auto i = 0; i < n; i++) {
      ll x;cin>>x;
      s+=x;
    }
    if(s&1 or (k*n%2==0))cout<<"yes";
    else cout<<"no";
    cout<<'\n';
  }
}

