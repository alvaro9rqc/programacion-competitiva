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

vi arr;
vector<vi> pos;
vi memo;
vi mep;
int n;

int dp(int i) {
  if (i>=n) return 0;
  if (memo[i]!=-1) return memo[i];
  int tam = arr[i]+1;
  int np = mep[i]+arr[i];
  if (np >= sz(pos[arr[i]])) return memo[i] = dp(i+1);
  np = (np < sz(pos[arr[i]])? pos[arr[i]][np]+1:n);
  return memo[i] =max(tam+dp(np), dp(i+1));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin>> tt;
  while(tt--) {
    cin >> n;
    arr.resize(n);
    for (auto i = 0; i < n; i++) cin >>arr[i],--arr[i];
    pos.assign(n,vi());
    mep.assign(n,0);
    for (auto i = 0; i < n; i++) {
      mep[i] = sz(pos[arr[i]]);
      pos[arr[i]].emplace_back(i);
    }
    //for(auto& i: mep) cout << i <<' ';
    //cout <<'\n';
    memo.assign(n,-1);
    //int ans = 0;
    //for (auto i = 0; i < n; i++) ans=max(ans, dp(i));
    cout << dp(0) <<'\n';
  }
}


