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

struct P {
  ll x,y;
};

using lll = tuple<ll,ll,ll>;
auto Us = [](lll a, lll b) {
  return get<0>(a) > get<0>(b);
};

struct UF {
	vl e;
	UF(ll n) : e(n, -1) {}
	bool sameSet(ll a, ll b) { return find(a) == find(b); }
	ll size(ll x) { return -e[find(x)]; }
	ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(ll a, ll b) {
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
  int n,q;cin>>n>>q;
  priority_queue<lll,vector<lll>, decltype(Us)> pq;
  vector<P> arr(n);
  for(auto& [x,y]: arr) cin >> x>>y;
  auto dist = [&](int i, int j) {
    P a=arr[i], b=arr[j];
    return abs(a.x-b.x) + abs(a.y-b.y);
  };
  UF uf(3009);
  for (auto i = 0; i < n-1; i++) 
    for (auto j = i+1; j < n; j++) 
      pq.emplace(dist(i,j), i,j);
  for (auto _ = 0; _ < q; _++) {
    int typ;cin>>typ;
    if(typ==1) {
      ll x,y;cin>>x>>y;
      arr.push_back({x,y});
      for (auto i = 0; i < sz(arr)-1; i++) {
        pq.emplace(dist(i,sz(arr)-1), i,sz(arr)-1 );
      }
    } else if (typ==2) {
      ll k=-1;
      while(sz(pq)) {
        auto [d, i, j] = pq.top();
        if (uf.sameSet(i,j)) {
          pq.pop();continue;
        }
        k = d; break;
      }
      // dbg(k);
      while(sz(pq)) {
        auto [d,i,j] = pq.top();
        if (uf.sameSet(i,j)) {
          pq.pop();continue;
        }
        if(d!=k) break;
        uf.join(i,j);
      }
      cout<<(k)<<'\n';
    } else {
      int i,j;cin>>i>>j;--i,--j;
      cout<<(uf.sameSet(i,j)?"Yes":"No")<<'\n';
    }
  }
}

