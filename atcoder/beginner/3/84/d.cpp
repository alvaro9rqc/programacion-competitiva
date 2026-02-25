#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, S; cin >> n >> S;
  vector<ll> a(n);
  ll sum = 0;
  for(auto& i: a) {
    cin >> i;
    sum += i;
  }
  S %= sum;
  a.insert(a.end(), a.begin(), a.end());
  set<ll> set;
  set.insert(0);
  ll acs = 0;
  for(auto& i: a) {
    acs += i;
    set.insert(acs);
  }
  for(auto& i: set) {
    if (set.find(S + i) != set.end()) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}


