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

int f(int n) {
  int ans = 0;
  while(n){
    ans+=n%10;
    n/=10;
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, k;cin>>n>>k;
  int ans = 0;
  for (auto i = 1; i <= n; i++)
  {
    int ds = f(i);
    if (ds==k)++ans;
  }
  cout<<ans<<'\n';
}

