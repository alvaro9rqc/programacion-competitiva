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

string f(string s) {
  string a;
  for(auto& c: s) 
  if (c!='A')a.push_back(c);
  return a;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  string s, t;cin>>s>>t;
  if (f(s)!=f(t)) {
    cout<<"-1\n";
    return 0;
  }
  int ans =0;
  for (auto si = 0,ti=0; ti<sz(t) or si<sz(s); ) {
    if (si<sz(s)) {
      if (ti<sz(t)){
        if (s[si]==t[ti])++ti,++si;
        else if (s[si]=='A') ++si, ++ans;
        else if (t[ti]=='A') ++ti, ++ans;
      } else ++ans,++si;
    } else if(ti<sz(t)) ++ans,++ti;
    // dbg(si);
    // dbg(ti);
    // dbg(ans);
  }
  cout<<ans<<'\n';
  return 0;
}

