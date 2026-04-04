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
  int n;cin>>n;
  vector<ii> ex(n);
  for(auto& [a,b]: ex) cin>>a>>b,--b;
  int m;cin>>m;
  vector<vector<vi>>alm(11,
                       vector<vi>(11,
                                  vi(30,0)));
  vector<string> strs(m);
  auto faa= [&](string& s, int d) {
    for (auto i = 0; i < sz(s); i++) alm[sz(s)][i][s[i]]+=d;
  };
  for(auto& i: strs) {
    cin>>i;
    for(auto& j: i) j-='a';
    faa(i,1);
  }
  for(auto& s: strs) {
    if(sz(s)!=n) {cout<<"No\n";continue;}
    bool can = 1;
    int xd = 0;
    for(auto& [a,b]: ex) {
      if (not( alm[a][b][s[xd]] )) can=0;
      ++xd;
    }
    cout<<(can?"Yes":"No")<<'\n';
  } 
}

