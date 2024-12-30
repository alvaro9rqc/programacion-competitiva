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
    string s; cin>>s;
    stringstream st(s);
    list<int>l;
    char ci;
    while (st >> ci) l.push_back((int)( ci-'0' ));
    vi ans;
    while (not l.empty()) {
      auto d = l.begin();
      auto d2=l.begin();
      int idx =0;
      int max = 0;
      while (d != l.end()) {
        if (9 - idx <= max) break;
        int v = *d - idx;
        if (v > max) 
        {
          max = v;
          d2=d;
        }
        idx++;
        d++;
      }
      d--;
      l.erase(d2);
      ans.push_back(max);
    }
    for(auto& i: ans) {
      cout << i;
    }
    cout << '\n';
  }
  return 0;
}


