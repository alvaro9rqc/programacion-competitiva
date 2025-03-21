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
  int t;
  cin >> t;
  while(t--) {
    int n, m, q;
    cin >> n >> m>>q;
    vi a(n);
    for(auto& e: a) cin >> e;
    vi b(m);
    for(auto& e: b) cin >> e;
    bool ya = true;
    unordered_set<int> vis;
    int idx=0;
    for(auto& s: b) {
      if (vis.find(s) == vis.end()) {
        vis.insert(a[idx++]);
        if (vis.find(s) == vis.end()){
          ya = false;
          break;
        }
      } 
    }
    if (ya) cout << "YA\n";
    else cout << "TIDAK\n";
  }
}


