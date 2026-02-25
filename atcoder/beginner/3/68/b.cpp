#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin  >> n;
  priority_queue<int> v;
  for (auto i = 0; i < n; ++i) {
    int x; cin >> x;
    v.push(x);
  }
  int ans = 0;
  while (v.size() > 1) {
    int x = v.top(); v.pop();
    int y = v.top(); v.pop();
    --x;--y;
    if (x != 0)
      v.push(x);
    if (y != 0)
    v.push(y);
    ++ans;
  }
  cout << ans << '\n';
  return 0;
}


