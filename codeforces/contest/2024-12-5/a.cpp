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
  while (t--) {
    int n; int m;
    string s; cin >> n >> m>>ws;
    int c=0;
    for (auto i = 0; i < n; ++i) {
      cin >> s>>ws; 
      //cout << "-> "<<s<<'\n';
      m -= s.size();
      if (m>=0) c++;
    }
    cout << c << '\n';
  }
  return 0;
}


