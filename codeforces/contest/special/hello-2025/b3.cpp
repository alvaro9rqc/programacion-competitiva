#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while (t--) {
    ll n, k; cin >> n >> k;
    map<ll,ll> s;
    for (ll i = 0; i < n; ++i) {
      ll x; cin >> x;
      ++s[x];
    }
    vector<ll> v;
    for(auto& [k,i]: s) {
      //cout << ": " << k <<' ' <<i<<'\n';
      v.push_back(i);
    }
    sort(v.begin(), v.end());
    int idx = 0;
    while (idx < v.size()-1) {
      if (k >= v[idx]) {
        //cout << "-> " << v[idx]<<'\n';
        k-=v[idx];
        ++idx;
      } else
        break;
    }
    cout << s.size() - idx<<'\n';
  }
  return 0;
}

