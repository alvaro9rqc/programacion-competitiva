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
  int n,k;cin>>n>>k;
  map<int,int> omp;
  for (auto i = 0; i < n; i++) {
    int x;cin>>x;
    ++omp[x];
  }
  vector<vi> val;
  vector<vi> las;
  auto [x,v]=*omp.begin();
  val.push_back({v});
  las.push_back({x});
  omp.erase(omp.begin());
  for(auto& [ke,va]: omp) {
    auto d=ke-las.back().back();
    if(d<=k) {
      las.back().push_back(ke);
      val.back().push_back(va);
    } else {
      las.push_back({ke});
      val.push_back({va});
    }
  }
  bool can = 0;
  for (auto i = 0; i < sz(val); i++) {
    auto& isl = val[i];
    if(sz(isl)==1) {
      if(isl.front()%2==0) {can=1;break;}
    } else {
      can=1;break;
    }
  }
  cout<<(can?"yes":"no")<<'\n';
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

