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
  while(t--) {
    int n; cin >> n;
    vector<int> b(n-2);
    for(auto& e: b) {
      cin >> e;
    }
    bool f = true;
    for (auto i = 1; i < b.size()-1; ++i) {
      if(b[i-1] == 1 and b[i] == 0 and b[i+1] == 1) {
        f = false; break;
      }
    }
    if(f) cout << "YES\n";
    else cout << "NO\n";

  }
}


