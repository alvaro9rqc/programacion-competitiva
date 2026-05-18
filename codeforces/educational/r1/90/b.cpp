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
vector<vi> memo;
int dp(int m, int i) {
  if(i==sz(arr)) return 0;
  if(memo[m][i]!=-1) return memo[m][i];
  auto& ans=memo[m][i];
  if(arr[i]==1) ans=min(
    1+dp(m,i+1),
    dp(m|(1),i+1)
  );
  else if(arr[i]==2) {
    if((m&1) or (m&4)) // si hay 1 o 3 no lo tomo
      ans=1+dp(m,i+1);
    else 
      ans=min(
        1+dp(m,i+1),
        dp(m|2,i+1)
      );
  } else if(arr[i]==3) {
    ans=min(
      1+dp(m,i+1),
      dp(m|4,i+1)
    );
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    string s;cin>>s;
    arr.resize(0);
    memo.assign(8,vi(sz(s),-1));
    for(auto& c: s) if(c!='4')arr.emplace_back(c-'0');
    int ans = dp(0,0);
    ans+=sz(s)-sz(arr);
    cout<<ans<<'\n';
  }
}

