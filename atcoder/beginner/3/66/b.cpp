#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  vector<string> S(n);
  int m = 0;
  for(auto& i: S) {
    cin >> i;
    if (i.size() > m) m = i.size();
  }
  vector<string>cop(m, string(n, '*'));
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < S[i].size(); ++j) {
      cop[j][n-i-1] = S[i][j];
    }
  }
  for(auto& s: cop) {
    for (auto i = s.size()-1; i >= 0; --i) {
      if (s[i] != '*') break;
      s[i] = ' ';
    }
  }
  for(auto& s: cop) {
    cout << s << '\n';
  }
  return 0;
}


