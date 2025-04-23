#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n>> m;
    vector<string> s(n);
    for(auto& e: s) cin >> e;
    int ri = 0;
    int ci = 0;
    for(auto& r: s) {
      int cr = 0;
      for(auto& c: r) {
        if (c == '1') ++cr;
      }
      ri += (cr & 1);
    }
    for (auto i = 0; i < m; ++i) {
      int cc = 0;
      for (auto j = 0; j < n; ++j) {
        if (s[j][i] == '1') ++cc;
      }
      ci += (cc & 1);
    }
    cout << max(ri,ci) << '\n';
  }
}


