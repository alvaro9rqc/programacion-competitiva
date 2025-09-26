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

ll n=0; 
ll m[11];

void f0(ll k) {
  cout << ( n & (1ll<<k) ? 1:0 ) << '\n';
};
void f1(ll k) {
  //cerr<< n << ":" << k << '\n';
  for (auto i = 0; i < 64; ++i) {
    if ( k & (1ll<<i) ) n |= (1ll<<i);
  }
};
void f2(ll k) {
  //cerr<< n << " " << k << '\n';
  for (auto i = 0; i < 64; ++i) {
    if ( k & (1ll<<i) ) n = n & ~(1ll<<i);
  }
};
void f3(ll k) {
  //cerr<< n << " " << k << '\n';
  for (auto i = 0; i < 64; ++i) {
    if ( k & (1ll<<i) ) n ^= 1ll<<i;
  }
};
void f4(ll k) {
  bool f = true;
  for (auto i = 0; i < 64; ++i) {
    if ( ( k & (1ll<<i) ) and  (n & (1ll<<i) ) == 0 ) {
      f = false; break;
    }
  }
  cout << (f? 1:0) <<'\n';
};
void f5(ll k) {
  bool f = false;
  for (auto i = 0; i < 64; ++i) {
    if ( ( k & (1ll<<i) ) and ( n & (1ll<<i) )  ) {
      f = true; break;
    }
  }
  cout << (f? 1:0) <<'\n';
};
void f6(ll k) {
  bool f = true;
  for (auto i = 0; i < 64; ++i) {
    if ( ( k & (1ll<<i) ) and ( n & (1ll<<i) )  ) {
      f = false; break;
    }
  }
  cout << (f? 1:0) <<'\n';
};
void f7(ll k) {
  int f = 0;
  for (auto i = 0; i < 64; ++i) {
    if ( ( k & (1ll<<i) ) and ( n & (1ll<<i) )  ) {
      ++f;
    }
  }
  cout << (f) <<'\n';
};
void f8(ll k) {
  cout << (n&k) <<'\n';
};


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ms; cin >> ms;
  for (auto i = 0; i < ms; ++i) {
    ll b;cin >> b;
    for (auto bi = 0u; bi < b; ++bi) {
      ll x; cin >> x;
      m[i] |= 1ll<<x;
    }
  }
  int q; cin >> q;
  for (auto i = 0; i < q; ++i) {
    int t, mi; cin >> t >> mi;
    if (t == 0) f0(mi);
    else if (t == 1) f1(m[mi]);
    else if (t == 2) f2(m[mi]);
    else if (t == 3) f3(m[mi]);
    else if (t == 4) f4(m[mi]);
    else if (t == 5) f5(m[mi]);
    else if (t == 6) f6(m[mi]);
    else if (t == 7) f7(m[mi]);
    else if (t == 8) f8(m[mi]);
  }
}


