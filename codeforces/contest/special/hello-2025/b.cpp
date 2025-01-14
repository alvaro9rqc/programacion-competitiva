#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while (t--) {
    ll n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto& i: a) {
      cin >> i;
    }
    if (k >= n-1) {
      cout << 1 << '\n';
      continue;
    }
    sort(a.begin(), a.end());
    vi c={1};
    for (ll i = 1; i < n; ++i) {
      if (a[i-1] != a[i]) c.push_back(1);
      else ++c.back();
    }
    sort(c.begin(), c.end());
    ll idx = 0;
    while (true) {
      if (k >= c[idx]) k-=c[idx];
      else break;
      ++idx;
    }
    cout << c.size() - idx << '\n';
  }
  return 0;
}


