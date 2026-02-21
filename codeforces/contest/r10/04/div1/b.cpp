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
    vl arr(n); for(auto& i: arr) cin>>i;
    map<ll,ll> omp;
    for (auto i = 0; i < n; i++) ++omp[arr[i]];
    ll mex = 0;
    for(auto& [k,v]: omp){
      if(k==mex)++mex;
    }
    if (mex==0) {
      cout<<n<<'\n';
      continue;
    }
    bool can = 1;
    for (auto i = 0; i < n; i++) {
      if(arr[i]==0) break;
      if(--omp[arr[i]]==0 and arr[i]<mex) mex=arr[i];
      if (arr[i]<mex) {
        can=0;
        break;
      }
    }
    cout<<(can?(n-omp[0]+1):n-omp[0])<<'\n';
  }
}

