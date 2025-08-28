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
  int tt; cin >> tt;
  while(tt--) {
    int n, k; cin >> n >>k;
    string s; cin >> s;
    multiset<char> cjn;
    for (auto i = 0; i < k-1; i++) cjn.insert(s[i]);
    bool can = 1;
    for (auto i = k-1; i < n; i++) {
      cjn.insert(s[i]);
      if (not cjn.count('0')) {can=0; break;}
      auto it = cjn.find(s[i-k+1]);
      cjn.erase(it);
    }
    if (not can) {cout << "no\n"; continue;}
    list<int> l;
    vi ans(n);
    for (auto i = 1; i < n+1; i++) l.emplace_back(i);
    for (auto i = 0; i < n; i++) {
      if (s[i] == '1') 
        ans[i]=(l.front()),
          l.pop_front();
    }
    for (auto i = 0; i < n; i++) {
      if (s[i] == '0') 
        ans[i]=(l.front()),
          l.pop_front();
    }
    cout <<"yes\n";
    for(auto& i: ans) cout << i << ' ';
    cout <<'\n';
  }
}


