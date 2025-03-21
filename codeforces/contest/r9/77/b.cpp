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
    int n,x;
    cin >> n >> x;
    vi a(n+1, 0);
    for (auto i = 0; i < n; ++i) {
      int e; cin >> e;
      if (e >= n) continue;
      a[e]++;
    }
    int i;
    for ( i = 0; i <= n; ++i) {
      if (a[i] == 0) {
        cout << i << '\n';
        break;
      }
      if (a[i]>1) {
        if  ( i+x < n ) {
          a[i+x]+= a[i]-1;
        }
      }
    }
  }
}


