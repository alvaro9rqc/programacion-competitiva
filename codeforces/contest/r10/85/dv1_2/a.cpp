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
    string s;cin>>s;
    string ma = s,mi=s;
    for (auto i = 0; i < n-2; i++) {
      if(ma[i]=='1' and ma[i+2]=='1')ma[i+1]='1';
      // if(mi[i]=='1' and mi[i+2]=='1')mi[i+1]='0';
    }
    mi=ma;
    for (auto i = 0; i < n-2; i++) {
      if(mi[i]=='1' and mi[i+2]=='1')mi[i+1]='0';
    }

    int ai, aa;
    ai=aa=0;
    for (auto i = 0; i < n; i++) {
      if(ma[i]=='1')++aa;
      if(mi[i]=='1')++ai;
    }
    cout<<ai<<' '<<aa<<'\n';
  }
}

