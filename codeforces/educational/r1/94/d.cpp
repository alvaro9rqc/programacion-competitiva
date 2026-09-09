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

void solve() {
  int n;cin>>n;
  vector<ii> arr;
  for (auto i = 0; i < n; i++) {
    char x;
    cin>>x;
    int f=0;
    if(x=='+')f=1;
    else if (x=='-')f=-1;
    if(sz(arr) == 0) arr.emplace_back(f, 1);
    else {
      auto& [si,s] = arr.back();
      if(si==f)++s;
      else arr.emplace_back(f,1);
    }
  }
  bool can = 1;
  can&= (arr[0].first!=0);
  for(auto& [f,s]: arr) 
  if(s>1 and f == 0) can=0;
  if(!can) {cout<<-1<<'\n'; return;}
  int m = sz(arr);
  vector<vi> dp(5, vi(m+1));
  for (auto i = 0; i < 5; i++) dp[i].back() = 0;
  for (auto i = m-1; i >= 0; i--) {
    for (auto j = 0; j < 5; j++) {
      int f = j-2;
      auto [fi, si] = arr[i];
      int n1=0,n2=0;
      n1 = 1;
      n2 = (si&1?1:2);
      if(fi==-1) {
        n1=-n1;
        n2=-n2;
      }else if (fi == 0) n1=0,n2=0;
      dp[j][i] = min(
        max(abs(n1-f), dp[n2+2][i+1]),
        max(abs(n2-f), dp[n1+2][i+1])
      );
    }
  }
  // dbg(dp[2][1]);
  cout<<dp[2][0]<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

