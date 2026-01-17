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

char abi='(';
char cer=')';

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    string s; cin >> s;
    vector<char> stk;
    vi clo(n), ope(n);
    ope.back()=n;
    clo.back()=1;
    for (auto i = n-2; i >=0; i--) {
      ope[i]=ope[i+1];
      if(s[i+1]=='(') ope[i]=i+1;
      clo[i]=(s[i]==cer)+clo[i+1];
    }
    int ans = -1;
    int xd = 0;
    for (auto i = 0; ope[i]!=n; i++) {
      if(s[i]==abi) {
        stk.emplace_back(abi);
        continue;
      }
      int j = ope[i]+1;
      //dbg(i);
      //dbg(j);
      //dbg(clo[j]);
      int pen;
      if ((pen=sz(stk)+1)<=clo[j]){
        //dbg(pen);
        //dbg(xd);
        //dbg((xd+clo[j])*2);
        //ans=max(ans,xd*2+1+clo[j]-sz(stk));
        ans=max(ans,(xd+clo[j])*2);
      }
      if(sz(stk)) stk.pop_back();
      ++xd;
      //if(!sz(stk))ans=max(ans,xd*2);
      //raya;
    }
    cout << ans<<'\n';
    //raya;
  }
}

