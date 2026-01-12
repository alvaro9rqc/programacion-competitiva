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
  int lim = 31;
  vector<vl>comb(lim, vl(lim,1));
  for (auto k = 1; k < lim; k++) {
    for (auto n = k+1; n < lim; n++) {
      comb[n][k]=comb[n-1][k]+comb[n-1][k-1];
    }
  }
  //dbg(comb[7][5]);
  vector<vl> pos(lim, vl(lim));
  for (auto b = 1; b < lim; b++) {
    pos[b][b]=1;
    for (auto o = b-1; o >=0; o--) {
      pos[b][o]=pos[b][o+1]+comb[b][o];
    }
  }
  //dbg(pos[4][2]);// con 5 espacios y 2 o
  int tt; cin >> tt;
  while(tt--) {
    ll n, k;  cin >> n >> k;
    int i = 31;
    for (; i >=0 and !(1ll<<i&n); i--);
    ll ans = 0;
    for (auto b = i-1; b > 0; b--) {
      ll r = k-(b+1);
      //r=max(0ll,r);
      if(r<b){
        if (r<0) r=-1;
        ans+=pos[b][r+1];
        //dbg(b);
        //dbg(r);
      }
    }
    if ((i+1)>k)++ans;
    cout << ans <<'\n';
    //raya;

    //ll ans = 0;
    //int ones = 0;
    //for (ll b = i; b > 0; b--) {
    //  if(1ll<<b&n)++ones;
    //  ll r;
    //  if (b!=i){
    //  //apago todo lo anterior y me quedo con ese
    //    r = k-(b+1);
    //    r=max(0ll,r);
    //    if (r<=b) {//menor o igual que los espacios
    //      ans+=pos[b][r];
    //    }
    //  }
    //  if(b!=i and((1ll<<i)&n)){
    //    // apago este bit pero mantengo el prefijo
    //    //lo que me pides menos los bits totales menos los prendidos antes de este
    //    //menos el que acabo de apagar
    //    r = k-(i+1+ones-1); 
    //    r=max(0ll,r);
    //    if(r<=b) //si lo que requiero es menor o igual a la cantidad de espacios
    //      ans+=pos[b][r];
    //  }
    //}
    //if(n&1)++ones;
    //if (ones+i>=k)++ans;
    //cout << ans <<'\n';
  }
  
}

