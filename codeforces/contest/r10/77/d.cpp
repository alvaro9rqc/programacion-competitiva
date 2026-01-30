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

int lim = 31;
int limr = 30;

pair<ll,ll> f(ll a, ll b) {
    ll m = a&b;
    //swap(a,b);
    int i = limr-1;
    for (; i >=0 and not(m&1ll<<i); i--);
    ll mb = b^m;
    //mayor
    ll mayor = mb;
    ll menor = mb;
    int xd=limr-1;
    for (int j = lim-1; j > i; j--) {
      if (not(a&1ll<<j) and not(b&1ll<<j))
        xd = j;
    }
    for (auto j = 0; j < xd; j++) 
      mayor&=~(1ll<<j);
    mayor|=1ll<<xd;
    if (mayor-b<abs(b-mb))mb=mayor;
    //menor
    for (auto j = 0; j < i; j++) {
      if (not(a&1ll<<j) and not(b&1ll<<j))
        menor |= (1ll<<j);
    }
    if (b-menor < abs(b-mb))mb=menor;
    //cout << a <<' '<<mb<<'\n';
    //dbg(abs(b-mb));
  return {a, mb};
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    ll a, b; cin >> a >> b;
    if(not (a&b)) {
      cout << a <<' '<<b<<'\n';
      continue;
    }
    auto[a1,b1]=f(a,b);
    auto[b2,a2]=f(b,a);
    if ((abs(a-a1)+abs(b-b1))>(abs(a-a2)+abs(b-b2))) {
      cout << a2<<' '<<b2<<'\n';
      dbg(abs(a-a2)+abs(b-b2));
    } else {
      cout << a1<<' '<<b1<<'\n';
      dbg(abs(a-a1)+abs(b-b1));
    }
  }
}

