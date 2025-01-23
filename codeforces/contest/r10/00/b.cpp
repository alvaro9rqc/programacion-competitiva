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
vll al, am, ar;


ll f(vll &a, ll ans) {
  for (auto i = 0; i < a.size() and i < am.size(); ++i) {
    if (a[i] < am[i]) {
      ans += a[i];
      ans -= am[i];
    } else break;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T; cin >> T;
  while (T--) {
    ll n, l , r; cin >> n >> l >> r ;
    al.clear();
    ar.clear();
    am.clear();
    for (auto i = 1; i < l; ++i) {
      ll x; cin >> x;
      al.push_back(x);
    }
    ll ans = 0;
    for (auto i = l; i < r+1; ++i) {
      ll x; cin >> x;
      ans += x;
      am.push_back(x);
    }
    for (auto i = r; i < n; ++i) {
      ll x; cin >> x;
      ar.push_back(x);
    }
    sort(al.begin(), al.end());
    sort(ar.begin(), ar.end());
    sort(am.begin(), am.end(), greater<ll>());
    //for(auto& i: al) {
    //  cout << i << ' ';
    //}
    //cout << "\n";
    //for(auto& i: am) {
    //  cout << i << ' ';
    //}
    //cout << "\n";
    //for(auto& i: ar) {
    //  cout << i << ' ';
    //}
    //cout << "\n";
    ans = min(ans, min( f(al, ans), f(ar, ans) ));
    cout << ans << '\n';
    //cout << "\n\n";
  }
  return 0;
}


