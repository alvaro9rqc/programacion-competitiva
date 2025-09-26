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
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int k; cin >> k;
  int m = 0;
  for (auto i = 0; i < k; ++i) {
    int x; cin >> x;
    m |= (1<<x);
  }
  for (auto i = m; i < (1<<n); ++i) {
    if ((i&m) >= m) {
      cout << i <<": ";
      for (auto j = 0; (1<<j) <= i; ++j) {
        if ((1<<j) & i) cout << j << " ";
      }
      cout<< '\n';
    }
  }
}


