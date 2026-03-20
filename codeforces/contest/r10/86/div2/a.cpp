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
    ll n;cin>>n;
    map<ll,ll> omp;
    for (auto i = 0; i < n*n; i++) {
      ll x;cin>>x;
      omp[x]++;
    }
    bool exi=1;
    for(auto& [k,v]: omp) {
      if(v>(n)*(n)-n) exi=0;
    }
    if(n==1) exi=0;
    cout<<(exi?"yes":"no")<<'\n';
  }
}

