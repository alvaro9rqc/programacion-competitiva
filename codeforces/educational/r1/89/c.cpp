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


int f=1;
int c=0;
int n;
int inf=4e6;
vector<string> s={"",""};
vector<vi> memo;

int dp(int m, int i) {
  if(i>=n)return 0;
  if(memo[m][i]!=-1)return memo[m][i];
  auto& ans=memo[m][i];
  if(m==f) {
    if(i==n-1) ans=inf;
    else {
      ans=0;
      ans+=(s[0][i]!=s[0][i+1])+(s[1][i]!=s[1][i+1]);
      ans+=min(
        dp(c,i+2),
        dp(f,i+2)
      );
    }
  } else {
    ans=0;
    ans+=(s[0][i]!=s[1][i]);
    ans+=min(
      dp(c,i+1),
      dp(f,i+1)
    );
  }
  // dbg(m==f);
  // dbg(i);
  // dbg(ans);
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    cin>>n;
    cin>>s[0]>>s[1];
    memo.assign(2,vi(n,-1));
    cout<<min(dp(c,0),dp(f,0))<<'\n';
  }
}

