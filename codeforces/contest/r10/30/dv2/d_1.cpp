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

const int pen=2,puede=1,no_p=0,nov=3;

vector<vector<vector<int>>> memo;
vl dly, pos;

int n,k;

int dp(int d, int i, int t) {
  if(memo[d][i][t]!=nov) return memo[d][i][t];
  int nd =d^(t==dly[i]);
  int ni=i+(nd?1:-1);
  if (ni == -1 or ni == n) return memo[d][i][t]=puede;
  memo[d][i][t]=pen;
  int nt = int((t+abs(pos[ni]-pos[i]))%k);
  //base
  if (memo[nd][ni][nt]==pen) return memo[d][i][t]=no_p;
  else return memo[d][i][t]=dp(nd,ni,nt);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    cin>>n>>k;
    pos.resize(n);
    dly.resize(n);
    dly.resize(n);
    memo.assign(2,vector<vector<int>>(n,vector<int>(k,nov)));
    for(auto& i: pos) cin >> i;
    for(auto& i: dly) cin >> i;
    int q;cin>>q;
    for (auto i = 0; i < q; i++) {
      ll x;cin>>x;
      if(x>pos.back()) {cout<<"yes\n";continue;}
      auto it=lower_bound(all(pos),x);
      cout<<(dp(1,int(it-pos.begin()),int((*it-x)%k))?"yes":"no")<<'\n';
    }
  }
}

