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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin>>tt;
  while(tt--){
    int n,m;cin>>n>>m;
    vector<vi>dp(11,vi(n));
    for (auto i = 0; i < m; i++) {
      int p,d,k;cin>>p>>d>>k;
      ++dp[d][p-1]=max(dp[d][p-1],k);
    }
    UF unf(n);
    for (auto i = 0; i < n; i++) {
      for (auto j = 1; j < 11; j++) {
        if(not dp[j][i])continue;
        unf.join(i,i+j);
        dp[j][i+j]=max(dp[j][i+j], dp[j][i]-1);
      }
    }
    set<int> ans;
    for (auto i = 0; i < n; i++) 
      ans.emplace(unf.find(i));
    cout<<sz(ans)<<'\n';
  }
}

