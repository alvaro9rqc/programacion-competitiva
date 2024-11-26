#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<ll> two(1,1);

const ll pr  = 131071;

void grow(ll n) {
  for (int i = two.size(); i <= n; ++i) {
    two.push_back(two.back() * 2 % pr);
  }

}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char c;
  string str="";
  while (cin >> c) {
    if (c != '#')  {
      str.push_back(c);
      continue;
    }
    grow(str.size());
    ll sum = 0;
    for (ll idx = str.size()-1; idx >= 0 ; --idx) {
      sum = ( (int)(str[idx] - '0')*two[idx] + sum ) % pr;
    }
    if (sum == 0) cout << "YES\n";
    else cout << "NO\n";
    str.erase();
  }
  return 0;
}


