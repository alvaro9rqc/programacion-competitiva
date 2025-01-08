#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool f(ll i, bool sw){
  if (i == 1) return sw;
  int log = 63 - __builtin_clzll(i);
  if (__builtin_popcountll(i) == 1) 
    return (log% 2 == 1) ^ sw;
  ll pot = 1ll << log;
  return f(i %pot, not sw);
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string S; cin >> S;
  ll n = S.size();
  ll Q; cin >> Q;
  vector<ll> K(Q);
  for(auto& i: K) {
    cin >> i;
  }

  auto swc = [](char x)->char {
    if (isupper(x)) return tolower(x);
    else return toupper(x);
  };
  for(auto& q: K) {
    bool g = f( (q-1)/n+1, false );
    if (g) cout << swc( S[(q-1) % n] ) << ' ';
    else cout << S[ (q-1) % n ] << ' ';
  }
  cout << '\n';
  return 0;
}


