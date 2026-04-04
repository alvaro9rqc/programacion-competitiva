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
    int x,y;cin>>x>>y;
    if(x>y) {
      cout<<"no\n";
    } else if (x==0) {
      if(y&1) {
        cout<<"yes\n";
        for (auto i = 1; i <= y-1; i++) cout<<"1 "<<i+1<<'\n';
      } else cout<<"no\n";
    } else {
      cout<<"yes\n1 2\n";
      for (auto i = 2; i <=x ; i++) {
        cout<<i*2-1<<' '<<i*2-2<<'\n';
        cout<<i*2<<' '<<i*2-1<<'\n';
      }
      for (auto i = 0; i < y-x; i++) cout<<x*2<<' '<<x*2+i+1<<'\n';
    }
  }
}

