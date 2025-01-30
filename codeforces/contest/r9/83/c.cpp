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
  int T;cin >> T;
  while(T--) {
    int n;cin>>n;
    vi v(n);
    for(auto& e: v) {
      cin >> e;
    }
    sort(v.begin(),v.end());
    int b=n-3,e=n-1;
    int ans = n;
    do {
      while(v[b]+v[b+1] > v[e]) {
        //cout << "-> " << e << '\n';
        ans = min(ans, n-1-e + b);
        if (!b) break;
        b--;
      }
      while(v[b]+v[b+1] <= v[e]) e--;
      ans = min(ans, n-1-e + b);
    }while(b);
    cout << ans << '\n';
  }
  return 0;
}


