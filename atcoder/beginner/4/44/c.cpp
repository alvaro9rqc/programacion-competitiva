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
  int n;cin>>n;
  vi k,v;
  map<int,int>omp;
  for (auto i = 0; i < n; i++) {
    int x;cin>>x;
    ++omp[x];
  }
  for(auto& [ki,vj]: omp) 
  v.emplace_back(vj),k.emplace_back(ki);
  if (n&1) {
    cout<<k.back()<<'\n';
  } else {
    set<int> ans;
    //sol max
    auto f=[&](int l, int r, int t) {
      bool can=1;
      for (; l<r; l++,--r) {
        if (v[l]==v[r] and k[l]+k[r]==t)continue;
        can=0;
        break;
      } 
      if (l==r) can&= v[l]%2==0 and k[l]<<1==t;
      return can;
    };
    int m=sz(omp);
    if (f(0, m-2, k[m-1])) ans.emplace(k[m-1]);
    if (f(0,m-1,k[0]+k[m-1]))ans.emplace(k[0]+k[m-1]);
    for(auto& i: ans)cout<<i<<' ';
    cout<<'\n';
  }
}


