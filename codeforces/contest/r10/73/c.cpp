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
  while(tt--){
    int n;cin>>n;
    string s; cin >> s;
    int r=n-1, l=0;
    int ones = 0;
    for(auto& i: s) if(i=='1')++ones;
    for (; l < n and s[l]=='0'; l++);
    for (; r >= 0 and s[r]=='1'; r--);
    if (r<=l) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
      vi ans;
      for (auto i = 0; i < n-ones; i++) 
        if (s[i]=='1')ans.emplace_back(i+1);
      for (auto i = n-ones; i < n; i++) 
        if (s[i]=='0')ans.emplace_back(i+1);
      cout << sz(ans)<<'\n';
      for(auto& i: ans) cout << i<<' ';
      cout <<'\n';
    }
  }
}

