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
    int n;cin>>n ;
    vi arr(n); for(auto& i: arr) cin>>i;
    map<int,int> omp;
    for (auto i = 1; i < n-2; i++) 
      if (arr[i-1]<arr[i] and arr[i]>arr[i+1])
        omp[arr[i]]=i;
    int l=0,vl=arr[0],r=n-1,vr=arr.back();
    int ans = 0;
    for (auto i = omp.rbegin(); i != om:p.rend(); i++) {
      auto [v,p]=*i;
      if (p<=l or p>=r)continue;
      int dr = r-p-(v<vr);
      int dl = p - l - (v<vl);

    }
  }
}

