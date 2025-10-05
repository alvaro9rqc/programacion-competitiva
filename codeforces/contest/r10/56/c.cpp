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

vi arr;

int bt(int i, int z, int o) {
  if (i == sz(arr)) return o?0:1;
  int ans = 0;
  if (z + o + 1== arr[i]) ans+=bt(i+1, z+1, o);
  if (z + o == arr[i] and o) ans+= bt(i+1, z, --o);
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    arr.resize(n);
    for(auto& i: arr) cin >> i;
    cout << bt(1, 1, arr[0]-1) + bt(1,0, arr[0]-1) <<'\n';
  }
}

