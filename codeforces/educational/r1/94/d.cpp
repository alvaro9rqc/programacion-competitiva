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
    auto [fi, si] = arr[i];
    vector<array<int,3>> p;
    if(fi == 0) p.push_back({0,0,1});
    else {
      if(si & 1) p.push_back({1,1,1});
      else  {
        if (si > 2) 
          p.push_back({1,1,2});
        p.push_back({1,2,1}),
        p.push_back({2,1,1});
      }
      if (fi==-1) 
        for(auto& [a,b,c]: p) a=-a,b=-b;
    }
    for (auto j = 0; j < 5; j++) {
      int ans = 3;
      int f = j-2;
      for(auto& [a,b,c]: p) 
      ans=min(ans,max({abs(a-f), dp[b+2][i+1], c}));
      dp[j][i]=ans;
    }
  }
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

