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
    int neg=0,pos=0,mi=0,ma=0;
    vi val(n);
    int xd=0;
    for(auto& i: val) {
      cin >> i;
      if(i<0)++neg;
      else if(i>0)pos++;
      if(i<val[mi])mi=xd;
      if(i>val[ma])ma=xd;
      ++xd;
    }
    vector<ii> ans;
    bool right=1;
    if(pos==0) right=0;
    else {
      if(abs(neg-pos)>5) {
        if(pos>neg) {
          for (auto i = 0; i < 5; i++) {
            ans.emplace_back(ma+1,ma+1);
            val[ma]*=2;
          }
          for (auto i = 0; i < n; i++) if(val[i]<0){
            ans.emplace_back(i+1,ma+1);
            val[i]+=val[ma];
          }
        } else {
          for (auto i = 0; i < 5; i++) {
            ans.emplace_back(mi+1,mi+1);
            val[mi]*=2;
          }
          for (auto i = 0; i < n; i++) if(val[i]>0) {
            ans.emplace_back(i+1,mi+1);
            val[i]+=val[ma];
          }
          right=0;
        }
      } else {
        if(val[ma]> -val[mi]) {
          for (auto i = 0; i < n; i++) 
            if(val[i]<0){ans.emplace_back(i+1,ma+1),val[i]+=val[ma];}
        }else {
          for (auto i = 0; i < n; i++) 
            if(val[i]>0){ans.emplace_back(i+1,mi+1),val[i]+=val[mi];}
          right=0;
        }
      }
    }
    if(right) {
      for (auto i = 1; i < n; i++) 
        ans.emplace_back(i+1,i);
    } else {
      for (auto i = n-2; i >= 0; i--) 
        ans.emplace_back(i+1,i+2);
    }
    cout<<sz(ans)<<'\n';
    for(auto& [i,j]: ans) cout<<i<<' '<<j<<'\n';
  }
}

