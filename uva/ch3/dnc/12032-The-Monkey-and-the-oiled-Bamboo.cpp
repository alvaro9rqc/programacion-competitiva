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
  int cse = 0;
  while(cse++ < T) {
    int n; cin >> n;
    vi r(n+1);
    r[0]=0;
    int ans = 0;
    for (auto i = 1; i <= n; ++i) {
      cin >> r[i];
      ans = max(ans, r[i]-r[i-1]);
    }
    int res = ans;
    for (auto i = 1; i <= n; ++i) {
      if(res < r[i]-r[i-1]) 
      {
        ++ans;
        break;
      }
      if(r[i]-r[i-1] == res) --res;
    }
    cout <<"Case "<<cse<<": "<< ans <<'\n';
  }
}


