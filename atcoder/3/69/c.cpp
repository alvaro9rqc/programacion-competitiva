#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n; 
vector<int> s;
ll f(int idx) {
  if (idx == n-1) return 1;
  ll ans = 2;
  ll d = s[idx+1] - s[idx];
  for (ll i = idx+2; i < n; ++i) 
    if (s[i] - s[i-1] == d) 
      ans += 1;
    else break;
  return ans*(ans+1)/2 -1 + f(idx + ans -1);
}
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  s.resize(n);
  for (auto i = 0; i < n; ++i) {
    cin >> s[i];
  }
  cout << f(0) << '\n';

  return 0;
}


