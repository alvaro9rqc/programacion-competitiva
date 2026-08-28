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

vi val;
int n;

int esc(int i, int j) {
  int mi = val[i];
  int ma = mi;
  for (auto k = i+1; k < j; k++) {
    if(val[k]!=mi-1 or val[k]!=ma+1) return k;
  }
  return j;
}

pair<vi,vi> sea(int i, int j) {
  vi st(n+1),fi(n+1);
  while(i!=j) {
    int k = esc(i,j);
    for (auto m = i; m < k; m++) {
      st[val[m]]=max(
        st[val[m]],
        k-m
      );
      fi[val[m]]=max(
        fi[val[m]],
        m-i+1
      );
    }
    i=k;
  }
  return {st,fi};
}

void solve() {
  cin>>n;
  val.resize(n);
  for(auto& i: val) cin>>i;
  int le=0;
  int ans = 0;
  while(le!=n) {
    int ri = esc(le,n);
    ans=max(ans,ri-le);
    auto[st, fi] = sea(ri,n);
    for (auto i = le; i < ri; i++) {
      if(val[i]+1<=n)
        ans=max(ans, i-le+1+st[val[i]+1]);//lo que hay antes + lo nuevo
      if(val[i]-1>=1)
        ans=max(ans, ri-i+fi[val[i]-1]);
    }
    le=ri;
  }
  dbg(ans);
  cout<<(ans/2)<<'\n';
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

