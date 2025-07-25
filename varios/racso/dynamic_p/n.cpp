#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)

string a, b;
int na, nb;
vector<vi> memo;
vector<vi> match;

int dp(int ai, int bi) {
  if (ai >= na or bi >= nb) return 0;
  if (memo[ai][bi] != -1) return memo[ai][bi];
  //no lo tomo
  int ans = dp(ai+1, bi);
  //lo tomo
  if (match[a[ai]][bi] != -1)
    ans = max(ans, 1+dp(ai+1, match[a[ai]][bi]+1));
  return memo[ai][bi] = ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> a >> b;
    na =(int) sz(a);
    nb =(int) sz(b);
    match.assign(130, vi(nb));
    memo.assign(na, vi(nb,-1));
    set<char> alf;
    for(auto& c: a) alf.insert(c);
    for(auto& c: alf) 
      for (auto i = nb-1; i >= 0; --i) {
        if (c == b[i]) match[c][i] = i;
        else match[c][i] = ( i == nb-1?-1:match[c][i+1] );
      }
    cout << dp(0,0) <<'\n';
  }
}


