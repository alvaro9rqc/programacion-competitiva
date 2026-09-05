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

ll fs(ll a, ll b, ll c, ll n) {
  if(!n) return b/c;
  ll k = a/c*n*(n+1)/2 + b/c*(n+1);
  a%=c;
  b%=c;
  if(!a) return k;
  ll m = (a*n+b)/c;
  return k + n*m- fs(c, c-b-1,a,m-1);
}

ll ival(ll a, ll b, ll c) {
  return c - (fs(b,c%b,a, c/b) + c/b+1 - 1);
}

ll bs(ll a, ll b, ll x) {
  ll l = 1; ll r = a*b-a-b;
  if(ival(a,b,r)<x)return -1;
  while(l!=r) {
    ll m = (l+r)/2;
    ll v = ival(a,b,m);
    if(v==x)r=m;
    else if (v>x)r=m-1;
    else l=m+1;
  }
  return l;
}

void solve() {
  ll a, b, k;cin>>a>>b>>k;
  cout<<bs(a,b,k)<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  // cin>>tt;
  while(tt--) {
    solve();
  }
}

