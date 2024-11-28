#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int last(ll n) {
  while(n > 9) n /= 10;
  return n;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll c;
  while (cin >> c) {
    if (c == 0 ) break;
    set<ll> s;
    for (auto i = 1; i < 10; ++i) {
      if (last(c + i) == i) s.insert(c+i);
    }
    for(auto& x: s) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}


