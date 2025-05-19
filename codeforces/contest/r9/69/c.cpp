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
  int t; cin >> t;
  while(t--) {
    ll n,a,b ; cin >> n>>a >> b;
    ll m = gcd(a,b);
    vl A(n);
    for(auto& e: A) cin >> e, e %= m;
    sort(A.begin(), A.end());
    auto it = unique(A.begin(), A.end());
    ll mid = ll(it - A.begin());
    if (mid & 1) mid /= 2;
    else mid /=2, mid-=1;
    ll ans = *(it-1) - A.front();
    //cout << "gcd: "  << m << '\n';
    //for(auto& e: A) cout << e << ' ';
    //cout << '\n';
    ll x1 = A.front() + m;
    ll x2 = A[mid]+ m;
    ans = min( ans, x1 - A[mid] );
    ans = min( ans, x2 - *(it-1) );
    ans = min(ans, max(A.front()+m-A[mid], m - ans) );
    ans = min(ans, max(x2-x1, ll(abs(x2  - *(it-1)))));
    //if (ans > m / 2) ans = min(ans, A.front()+m-A[mid] );
    cout << ans << '\n';
  }
}


