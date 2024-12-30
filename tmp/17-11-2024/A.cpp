#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    unordered_set<int> s;
    int x;
    int sum = 0;
    for (auto i = 0; i < n; ++i) {
      cin >> x;
      if (s.find(x) != s.end()) {
        s.erase(x);
        sum ++;
      } else s.insert(x);
    }
    cout << sum << '\n';
  }
  return 0;
}


