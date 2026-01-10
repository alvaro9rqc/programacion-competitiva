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
  int n; cin >> n;
  vector<ii> arr(n);
  for (auto i = 1; i < n+1; i++) {
    int t; cin >> t;
    arr[i-1]={t,i};
  }
  sort(all(arr));
  cout << arr[0].second<<" "<<arr[1].second<<" "<<arr[2].second<<'\n';
}

