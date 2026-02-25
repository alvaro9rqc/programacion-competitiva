#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vector<int> v(n);
  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }
  multiset<ll> s;
  for (ll i = 0; i < n-1; ++i) {
    ll x;
    cin >> x;
    s.insert(x);
  }
  bool f = true;
  ll x=-1;
  sort(v.rbegin(), v.rend());
  for (ll i = 0; i < n; ++i) {
    auto it = s.lower_bound(v[i]);
    if (it == s.end()) {

      //cout <<v[i] <<" - "<< *it << ' ' << s.size() << "->\n";
      if (f) {
        x = v[i];
        s.insert(v[i]);
        it = s.find(x);
        //cout << "-> " << *it << '\n';
        f = false;
      } else {
        //cout << ": " << v[i] << '\n';
        x = -1;
        break;
      }
    } 
    s.erase(it);
  }
  cout << x << '\n';
  return 0;
}


