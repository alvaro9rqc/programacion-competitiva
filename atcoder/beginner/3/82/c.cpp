#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  vector<ll> e;
  vector<ll> pos;
  ll elm;
  cin >> elm ;
  e.push_back(elm);
  map<ll,ll> ma;
  ma[elm]=1;
  for (auto i = 2; i <= n; ++i) {
    ll ne; cin >> ne;
    if (ne < elm) {
      elm=ne;
      e.push_back(elm);
      ma[elm]=i;
    }
  }
  reverse(e.begin(), e.end());
  for (auto i = 0; i < m; ++i) {
    ll x; cin >> x;
    auto f = upper_bound(e.begin(), e.end(), x);
    f--;
    if (f >= e.begin()) {
      cout << ma[*f]<<'\n';
    } else cout << -1<<'\n';
  }
  return 0;
}


