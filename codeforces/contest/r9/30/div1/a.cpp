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
  int tt;cin>>tt;while(tt--) {
    int n;cin>> n; 
    //mayor 
    int im=0;
    auto preg=[](int a, int b, int c, int d) {
      cout<<format("? {} {} {} {}",a,b,c,d)<<endl;
    };
    for (auto i = 0; i < n; i++) {
      preg(im,im,i,i);
      char c;cin>>c;
      if(c=='<')im=i;
    }
    //comb
    vi ids;
    int lt=im;
    for (auto i = 0; i < n; i++) {
      preg(im,i,im,lt);
      char c;cin>>c;
      if(c=='>') {
        ids.clear();
        ids.emplace_back(i);
        lt=i;
      } else if (c=='=') ids.emplace_back(i);
    }
    // men
    int ime = ids.front();
    for(auto& i: ids) {
      preg(i,i, ime,ime);
      char c;cin>>c;
      if(c=='<') ime=i;
    }
    cout<<"! "<<im<<' '<<ime<<endl;
  }
}

