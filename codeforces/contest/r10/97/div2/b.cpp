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
    int n;cin>>n;
    map<ll,int> omp;
    for (auto i = 0; i < n; i++) {
      ll x;cin>>x;
      ++omp[x];
    }
    vl val;
    auto it=omp.end();
    --it;
    val.emplace_back(it->first);
    --(it->second);
    for(auto& [k,v]: omp) {
      if(v){
        val.emplace_back(k);
        --v;
      }
    }
    for(auto& [k,v]: omp) {
      for (auto i = 0; i < v; i++) val.emplace_back(k);
    }

    ll mex=0,mva=0;
    ll ans = 0;
    set<ll> ost;
    for (auto i = 0; i < n; i++) {
      ost.emplace(val[i]);
      if(val[i]>mva)mva=val[i];
      while(ost.count(mex))++mex;
      ans+=mex+mva;
    }
    cout<<ans<<'\n';
  }
}

