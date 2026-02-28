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
  string s;cin>>s;
  map<char,int>omp;
  int m = 0;
  for(auto& c: s) ++omp[c], m=max(m,omp[c]);
  string ans;
  for(auto& c: s) {
    if (omp[c]!=m)ans.push_back(c);
  }
  cout<<ans<<'\n';
}

