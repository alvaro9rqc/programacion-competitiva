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
  for(auto& i: a) {
    cin >> i;
  }
  ll acs = 0;
  ll sum = 0;
  unordered_set<ll> s;
  bool f = false;
  for(auto& i: a) {
    acs += i;
    s.insert(acs);
  }
  s.insert(0);
  sum = acs;
  S %= sum;
  if (s.find(S) != s.end()) {
    f = true;
    goto label;
  }
  cout << "-> " << S << '\n';
  for(auto& i: a) {
    acs -= i;
    cout << S << ": " << S - acs << '\n';
    if (S == acs or ( s.find(S-acs) != s.end() )) {
      f=true;
      goto label;
    }
  }
label: 
  if (f)
    cout << "YES\n";
  else 
    cout << "NO\n";
  return 0;
}


