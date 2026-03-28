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
    int n,k;cin>>n>>k;
    vi arr(n),brr(n);
    for(auto& i: arr) cin >> i;
    for(auto& i: brr) cin >> i;
    map<int,int> omp;
    for (auto i = n-k; i < k; i++) omp[brr[i]]++;
    bool can = 1;
    for (auto i = n-k; i < k; i++) {
      if(omp[arr[i]]>0) omp[arr[i]]--;
      else if (omp[-1]>0) omp[-1]--;
      else can=0;
    }
    for (auto i = 0; i < n-k; i++) can&=(arr[i]==brr[i] or brr[i]==-1);
    for (auto i = k; i < n; i++) can&=(arr[i]==brr[i] or brr[i]==-1);
    cout<<(can?"yes":"no")<<'\n';
  }
}

