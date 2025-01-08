#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> H(n);
  for(auto& i: H) {
    cin >> i;
  }
  int ans = 1;
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < i; ++j) {
      int k = j;
      int last = H[k];
      int lans = 0;
      while (k < n) {
        if (H[k] == last) lans++;
        else {
          last = H[k];
          ans = max(ans, lans);
          lans = 1;
        }
        k+=i;
      }
      ans = max(lans, ans);
    }
  }
  cout << ans << '\n';
  return 0;
}


