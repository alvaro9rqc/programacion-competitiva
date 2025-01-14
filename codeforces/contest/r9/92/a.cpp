#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    int n, k; cin >> n >>k;
    vector<int> v(n);
    for (auto i = 0; i < n; ++i) {
      cin>>v[i];
    }
    bool f = true;
    for (auto i = 0; i < n; ++i) {
      f = true;
      for (auto j = 0; j < n; ++j) {
        if (j == i) continue;
        int d = (int)abs(v[i]-v[j]);
        if(d % k == 0) 
        {
          f = false;
          break;
        }
      }
      if (f) {
        cout << "YES\n" << i + 1 << '\n';
        break;
      }
    }
    if (!f)
      cout << "NO\n";
  }
  return 0;
}


