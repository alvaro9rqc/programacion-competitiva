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
  string s,t;
  cin>>s>>t;
  for(auto& i: s) i-='a';
  for(auto& i: t) i-='a';
  int alf = 30;
  vector<vi> ocu(alf, vi(sz(s)+1,sz(s)));
  for (auto i = sz(s)-1; i >= 0; i--) {
    for(auto& j: t) {
      ocu[j][i]=ocu[j][i+1];
      if(j==s[i])ocu[j][i]=i;
    }
  }
  auto f=[&](int j) {
    for (auto i = 0; i < sz(t); i++) {
      j=ocu[t[i]][j];
      if(j==sz(s)) return j;
      j++;
    }
    return j-1;
  };
  ll ans = 0;
  for (auto i = 0; i < sz(s); i++) {
    ans+=f(i)-i;
  }
  cout<<ans<<'\n';
}

