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
  while(tt--){
    int n,m,l;cin>>n>>m>>l;
    vi arr(n);
    for(auto& i: arr) cin >> i;
    int len = min(m, n+1);
    vi ani(len);
    for (auto i = 0; i < n; i++) {
      int dl=arr[i]-(i?arr[i-1]:0);
      int j = 1;
      while(dl){
        if (j==len or ani[j]!=ani[j-1]) {
          for (auto k = j-1; k >= 0 and dl; k--) 
            --dl, ani[k]++;
        } else ++j;
      }
      // dbg(ani[0]);
      // dbg(ani[1]);
      len=min(m,n-i);//nuevo len
      if(len<sz(ani))ani.pop_back();
      else {
        rotate(ani.rbegin(),ani.rbegin()+1,ani.rend());
        ani[0]=0;
      }
    }
    cout<<ani.back()+l-arr.back()<<'\n'; 
  }
}

