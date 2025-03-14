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
  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    vi a(n);
    unordered_map<int,int> m;
    for(auto& e: a) {
      cin >> e;
      m[e]++;
    }
    int al=0,ar=-1,l=-1;
    for (auto i = 0; i < n; ++i) {
      if (m[a[i]] == 1) {
        if (l == -1) l = i;
        if (i - l > ar - al) {
          ar = i;
          al = l;
        }
      } else l = -1;
    }
    if (ar == -1) cout << 0 <<'\n';
    else cout << al+1 <<' ' << ar +1 <<'\n';
  }
}


