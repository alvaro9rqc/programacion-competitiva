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
    string s,t;cin>>s>>t;
    queue<char> que;
    for(auto& i: s) que.emplace(i);
    map<char,int> omp;
    for(auto& i: t) omp[i]++;
    bool can = 1;
    for(auto& i: s) omp[i]--, can&=(omp[i]>=0);
    if(not can) {
      cout<<"Impossible\n";
      continue;
    }
    string ans = "";
    auto p=[&](char x, int r) {
      for (auto i = 0; i < r; i++) ans.push_back(x);
    };
    for(auto& [k,v]: omp) {
      while(sz(que) and que.front() <= k) {
        p(que.front(), 1);
        que.pop();
      }
      p(k,v);
    }
    cout<<ans<<'\n';
  }
}

