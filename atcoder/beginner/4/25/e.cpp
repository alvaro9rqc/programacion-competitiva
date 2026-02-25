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

vi primos;
int np=0;
vector<vi> table;
const int lim = 5001;
bitset<lim> bs;

void sieve(){
  bs.set();
  bs[0]=bs[1]=0;
  for (auto i = 2; i < lim; i++) 
    if(bs[i]) {
      for (auto j = i*i; j < lim; j+=i) 
        bs[j]=0;
      primos.emplace_back(i);
    }
  np = sz(primos);
  table.emplace_back();
  table.emplace_back(np);
  for (auto i = 2; i < lim; i++) {
    table.emplace_back(all(table.back()));
    int n = i;
    for(int j = 0; j < np; j++) {
      auto p = primos[j];
      if (p*p>n) break;
      while(!(n%p)){
        ++table[i][j];
        n/=p;
      }
    }
    for (auto j = 0; j < np; j++) 
      if (primos[j]==n) ++table[i][j];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  sieve();
  //for (int i = 0; i < np; ++i) {
  //  if (table[21][i])
  //    cout << primos[i] << ' '<<table[21][i]<<'\n';
  //}
  int tt; cin >> tt;
  int m; cin >> m;
  while(tt--) {
    int n; cin >> n;
    auto vp = table[1];
    int sn = 0;
    for (auto i = 0; i < n; i++) {
      int c; cin >> c;
      sn+=c;
      auto& pri = table[c];
      for (auto j = 0; j < np; j++) 
        vp[j]-=pri[j];
    }
    //ans
    ll ans = 1;
    for (auto i = 0; i < np; i++) {
      vp[i]+=table[sn][i];
      for (auto j = 0; j < vp[i]; j++) 
        ans*=primos[i], ans%=m;
    }
    cout << ans <<'\n';
  }
}

