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

string s;
vector<int>memo;

int dp(int i) {
  if (i < 0 or i >= sz(s)) return 0;
  if (memo[i]!=-1) return memo[i];
  if (s[i]=='>') return memo[i] = 1 + dp(i+1);
  if (s[i]=='<') return memo[i] = 1 + dp(i-1);
  return memo[i] = 1 + max(dp(i-1), dp(i+1));
}

bool fore() {
  if (s.find(">*") != string::npos) return 1;
  if (s.find("*<") != string::npos) return 1;
  if (s.find("**") != string::npos) return 1;
  if (s.find("><") != string::npos) return 1;
  return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> s;
    if (fore()) {
      cout << -1<<'\n';
    } else {
      int ans = 0;
      int n = sz(s);
      memo.assign(n,-1);
      for (auto i = 0; i < n; i++) 
        ans = max(dp(i), ans);
      cout << ans <<'\n';
    }
  }
}


