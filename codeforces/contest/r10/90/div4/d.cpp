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
  const ll lim=ll(1e6);
  bitset<lim> bt;
  vl p;
  bt.set();
  bt[0]=bt[1]=0;
  for (auto i = 2ll; i < lim; i++) if(bt[i]) {
    for (auto j = i*i; j < lim; j+=i) bt[j]=0;
    p.emplace_back(i);
  }

  while(tt--) {
    int n;cin>>n;
    for (auto i = 0; i < n; i++) cout<<(p[i]*p[i+1])<<' ';
    cout<<'\n';
  }
}

