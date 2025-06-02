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
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;

void f(ll b) {
  for (auto i = 31; i >= 0; --i) {
    cout << (b & (1ll<<i)?1:0);
  }
  cout << '\n';
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a,b; cin >> a >> b;
  f(a&b);
  f(a|b);
  f(a^b);
}



