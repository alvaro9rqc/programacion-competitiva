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
    int n,m;cin>>n>>m;
    vl arr(n);
    vl brr(m);
    for(auto& i: arr) cin >> i;
    for(auto& i: brr) cin >> i;
    sort(brr.rbegin(), brr.rend());
    for (auto i = 0,j=0; i < n or j<m ;) {
      ll p;
      if(i==n) p=brr[j],j++;
      else if(j==m) p=arr[i],i++;
      else if(brr[j]>=arr[i])p=brr[j++];
      else p=arr[i++];
      cout<<p<<' ';
    }
    cout<<'\n';
  }
}

