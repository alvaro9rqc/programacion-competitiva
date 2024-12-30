#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; string s;
  cin >> n >> s;
  vector<ll> sum(n, 0);
  vector<int> sol;
  ll r=0;
  sum[0] =(ll) ( s[0]-'0' );
  for (auto i = 1; i < n; ++i) {
    sum[i] = sum[i-1] + (i+1)*(ll)( s[i]-'0' );
  }
  for (auto i = n-1; i >= 0; --i) {
    sol.push_back(( sum[i] + r) % 10);
    r = ( sum[i]+r ) / 10;
  }
  while (r) {
    sol.push_back(r % 10);
    r /= 10;
  }
  for (auto rit = sol.rbegin(); rit != sol.rend(); ++rit) {
    cout << *rit ;
  }
  cout << '\n';
  return 0;
}


