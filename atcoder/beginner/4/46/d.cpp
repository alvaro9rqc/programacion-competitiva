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
  map<int,int>omp;
  vi arr(n); for(auto& i: arr) cin>>i;
  omp[arr.back()]=1;
  for (auto i = n-2; i >= 0; i--) {
    int a = arr[i];
    if (omp.count(a+1))omp[a]=omp[a+1]+1;
    else omp[a]=1;
  }
  int ans = 0;
  for(auto& [k,v]: omp) ans=max(ans,v);
  cout<<ans<<'\n';
}

