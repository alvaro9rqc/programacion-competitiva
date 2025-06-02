#include <bits/stdc++.h> 
using namespace std;
using ll = unsigned long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll i = 0;
  int n ; cin >> n;
  for (auto k = 0; k < n; ++k) {
    int a, b; cin >> a;
    if (a < 4) cin >> b;
    if (a == 1) { i |= 1ull<<b; }
    else if (a == 2) { i = i & ~(1ull<<b); }
    else if (a == 3) { i ^= 1ull << b; }
    else if (a == 4) { cout << ( i == ~(0ull)?1:0 )<<'\n'; }
    else if (a == 5) { cout << ( i ? 1:0 ) << '\n'; }
    else if (a == 6) { cout << ( i==0 ? 1:0 ) << '\n'; }
    else if (a == 7) { cout << __builtin_popcountll(i) << '\n'; }
    else if (a == 8) { cout << (i) << '\n'; }
    else if (a == 0) { cout << ( (i & (1ull<<b)?1:0) )<<'\n'; }
    //cout <<"gg: " <<i <<'\n';
  }
}


