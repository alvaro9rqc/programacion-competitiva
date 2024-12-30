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
    for (auto i = 0; i < 10; ++i) {
      if (( c - i )%9 == 0) s.insert((c-i) / 9 * 10 + i);
    }
    auto it = s.begin();
    cout << *it;
    it++;
    while(it != s.end()) cout << ' ' << *it++;
    cout << '\n';
  }
  return 0;
}


