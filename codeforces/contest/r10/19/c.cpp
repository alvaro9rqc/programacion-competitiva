#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;


template<typename IT>
IT f(IT b, IT e) {
  int ans = *b;++b;
  for ( ; b != e; ++b) {
    if (ans >= 0 and *b > 0) break;
    if (ans == 0) break;
    ans += *b;
  }
  if (ans >= 0) return b-1;
  return b;
}

bool f2(vi& a) {
  auto p = f(a.begin(), a.end()-2);
  if (p < a.end()-2) {
    auto pm = f(p+1, a.end()-1);
    if (pm < a.end()-1) return true;
    else {
      auto pr = reverse_iterator(p);
      pr-=2;
      auto c = f(a.rbegin(), pr);
      if (c < pr) return true;
    }
  }
  return false;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll tt; cin >> tt;
  while(tt--){
    ll n, k; cin >> n >> k;
    vi a(n);
    for(auto& e: a) {
      ll x; cin >> x;
      e = x <= k ? 1:-1;
    }
    if (f2(a)) cout << "yes\n";
    else {
      //cerr << "second ";
      reverse(a.begin(), a.end());
      if (f2(a)) cout << "yes\n";
      else cout << "no\n";
    }

  }
}


