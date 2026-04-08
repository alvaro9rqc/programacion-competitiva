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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n; cin>>n;
    map<int,int> now,nex;
    for (auto i = 0; i < n; i++) {
      int x;cin>>x;
      ++now[x];
    }
    for (auto i = 0; i < n-1; i++) {
      for(auto& [k,v]: now) if(v>1)
        nex[0]+=v-1;
      for (auto a = now.begin(), b=++now.begin(); b!=now.end(); a++,++b) {
        ++nex[b->first - a->first];
      }
      now.clear();
      swap(nex,now);
    }
    cout<<(now.begin()->first)<<'\n';
  }
}

