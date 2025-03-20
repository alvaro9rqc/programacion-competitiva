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

vi a;

bool r(int i) {
  if( i== 0 ) return a[i]-- > 1;
  if (a[i]> 1) {
    a[i]--;
    return true;
  }
  if (a[i]==1) return r(i-1);

  //n==0
  a[i]=1;
  return r(i-1) and r(i-1);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    int n;
    cin >> n;
    a.assign(n,0);
    for (auto i = 0; i < n; ++i) {
      int x; cin >> x;
      a[x-1]++;
    }
    bool can = true;
    for (auto i = n-1; i > 0; --i) {
      if (a[i] & 1 and not r(i-1)) {
        can = false;
        break;
      }
    }
    if (can) cout << "Yes\n";
    else cout << "No\n";
  }
}


