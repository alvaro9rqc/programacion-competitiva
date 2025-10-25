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

int n;
string s;
using pri = priority_queue<int,vi, greater<int>>;
vector<pri> pq;
vector<vi> ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  vi mv = {-1,1,2,0,1,2};
  while(tt--) {
    cin >> s;
    n = sz(s);
    pq.assign(3, pri());
    ans.assign(n/6, vi());
    for (auto i = 0; i < n/6; i++) pq[1].emplace(i);
    for (auto i = 0; i < n; i++) {
      int c = s[i]-'0';
      if (pq[c].empty()) {cerr<<"gaaa\n";cerr<<i<<'\n'; break;}
      int j = pq[c].top(); pq[c].pop();
      ans[j].emplace_back(1+i);
      if (sz(ans[j]) < 6) 
        pq[mv[sz(ans[j])]].emplace(j);
    }
    for(auto& r: ans) 
    for(auto& i: r) cout << i << " \n"[ &i == &r.back() ];
    raya;
  }
}

