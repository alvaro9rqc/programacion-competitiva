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

ll mod = 998244353;
ll f(ll e) {
  ll r = 1;
  ll b = 2;
  while(e) {
    if(e&1) {
      r*=b;
      r%=mod;
    }
    e>>=1;
    b*=b;
    b%=mod;
  }
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,m;cin>>n>>m;
  UF ufd(n);
  using lll = tuple<int,int,int>;
  using vlll = vector<lll>;
  vlll edgs;
  for (auto i = 1; i <= m; i++) {
    int x,y;cin>>x>>y;
    --x,--y;
    edgs.emplace_back(i,x,y);
  }
  reverse(all(edgs));
  ll ans = 0;
  int cx = n;
  for(auto& [w,u,v]: edgs) {
    if (ufd.find(u)!=ufd.find(v) and cx==2) {
      //no lo tomo
      ans+=f(w);
      ans%=mod;
    } else {
      //lo tomo
      cx-=ufd.join(u,v);
    }
  } 
  cout<<ans<<'\n';
}

