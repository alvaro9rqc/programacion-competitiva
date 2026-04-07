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
  while(tt--){
    ll n,m,a,b;cin>>n>>m>>a>>b;
    if(gcd(a,n)==1 and gcd(m,b)==1 and (m<=2 or n<=2 or gcd(m,n)<=2) )
      cout<<"yes";
    else cout<<"no";
    cout<<'\n';
  }
}

