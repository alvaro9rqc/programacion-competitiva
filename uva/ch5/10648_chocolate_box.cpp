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
  int n,m;
  int cases = 0;
  while(1) {
    cin >> n;
    if (n==-1) break;
    cin >> m;
    vector<double> now(n+1), pre(n+1);
    pre[0]=1;
    for (auto j = 1; j < m+1; j++) {
      for (auto i = 1; i < n+1; i++) {
        if (i < j) 
          now[i]=0;
        else 
          now[i] = (j*1.0) /double(m) * now[i-1]+ pre[i-1]*(double(m-j+1)/double(m));
      }
      swap(now,pre);
    }
    printf("Case %d: %0.7lf\n", ++cases, 1.0-pre[n]);
  }
}

