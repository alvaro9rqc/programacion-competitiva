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


vector<ii> d;
//using vvvi = vector<vector<vi>>;
//vector<vvvi> memo;
int k, n;

const int MAXK = 361;
static int memo[2][MAXK][MAXK][MAXK];


int dp(bool f, int s, int m, int i) {
  if (memo[f][s][m][i]!=-1) return memo[f][s][m][i];
  if (i==sz(d)-1) {
    if (f)
      return memo[f][s][m][i] = max(m, min(d[i].first,k-s+m))*(n-d[i].second);
    else 
      return memo[f][s][m][i] = max(m, min(d[i].first,k-s))*(n-d[i].second);
  }
  int ans = 0;
  int ap = k -s;
  int dd= d[i+1].second - d[i].second;
  if (f) {
    ans = dd*m+dp(0, s,m,i+1);
    if (ap and m < d[i].first) ans=max(ans, dp(1, s+1,m+1,i));
  } else {
    ans = dd*m+dp(0,s,m,i+1);
    if (ap > m and m < d[i].first) ans=max(ans,dp(1,s+m+1,m+1,i));
  }
  //dbg(f);
  //dbg(s);
  //dbg(m);
  //dbg(i);
  //dbg(ans);
  //raya;
  return memo[f][s][m][i]=ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n>>k;
    //memo.assign(2, vvvi(k+1,vector<vi>(k+1,vi(k+1,-1))));
    vi arr(n); for(auto& i: arr) cin >> i;
    int a, c,e;
    a=2;
    c=arr.front();
    d= {{arr.front(), 0}};
    for (auto i = 1; i < n; i++) {
      c=max(c,arr[i]);
      if (d.back().first < arr[i]) 
        d.emplace_back(arr[i], i);
    }
    e=sz(d);
    for (auto i = 0; i < a; i++) 
      for (auto j = 0; j < k+1; j++) 
        for (auto r = 0; r < c+1; r++) 
          for (auto l = 0; l < e+1; l++) 
            memo[i][j][r][l]=-1;
    //for(auto& [v,i]: d) cout <<v<<' '<<i<<'\n';
    cout << dp(0, 0,0,0)<<'\n';
  }
}

