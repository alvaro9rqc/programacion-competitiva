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
    if (n == 6) {
      cout << "1 1 2 3 1 2\n";
      continue;
    }
    for (auto i = 1; i <= n/2; ++i) {
      cout << i << ' ';
    }
    if(n&1) cout << n/2+1<<' ';
    for (auto i = 1; i <= n/2; ++i) {
      cout << i << ' ';
    }
    cout <<'\n';
  }
  return 0;
}


