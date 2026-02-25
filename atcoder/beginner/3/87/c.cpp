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

ll mpow(ll b, ll e) {
  ll ans = 1;
  for (auto i = 0; i < e; ++i) {
    ans *= b;
  }
  return ans;
}

ll h(int lim, string n) {
  if (n.size() == 1) return min(lim, int(n[0]-'0')+1);
  int f = int(n[0]-'0');
  if (f >= lim) return mpow(lim, n.size());
  ll a = f*mpow(lim, n.size()-1);
  return a+h(lim,n.substr(1,n.size()-1));
}

ll g(int d, int s) {
  if (s == 1) return 0;
  if (d == 0) return g(9,s-1);
  return mpow(d, s-1) + g(d-1, s);
}

ll f(string n) {
  if (n == "10") return 1;
  ll a = g(int(n[0]-'0')-1, n.size());
  ll b = h(int(n[0]-'0'), n.substr(1,n.size()-1));
  //cout << "-> " << a <<'\n';
  //cout << "-> " << b <<'\n';
  return a + b;
}

int is(string n) {
  char f = n[0];
  for (auto i = 1; i < n.size(); ++i) {
    if (f <= n[i]) return 0;
  }
  return 1;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string l,r; 
  cin >> l >> r;
  int p = is(l);
  //cout << f("1000000000000000000")<<'\n';
  //cout <<  f("999999999999999999")<<'\n';
  //cout << mpow(9, 17)<<'\n';
  cout << f(r) - f(l) + p<<'\n';
  return 0;
}


