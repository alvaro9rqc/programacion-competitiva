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
    int n,d;cin>>n>>d;
    vi arr(n),brr(n);
    for(auto& i: arr) cin>>i;
    for(auto& i: brr) cin>>i;
    queue<int>que;
    for (auto i = 0; i < n; i++) {
      for (auto j = 0; j < arr[i]; j++) que.emplace(i);
      for (auto j = 0; j < brr[i]; j++) que.pop();
      while(sz(que) and i-que.front()>=d) que.pop();
    }
    cout<<sz(que)<<'\n';
  }
}

