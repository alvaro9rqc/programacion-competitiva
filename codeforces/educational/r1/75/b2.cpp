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

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T; cin >> T;
  while(T--) {
    ll n, x, k; cin >> n >> x >> k;
    string s; cin >> s;
    ll x_i = x;
    bool z_pos = false;
    ll l=x, r=x;
    ll ans = 0;
    for(auto& c: s) {
      if (c == 'L') x--;
      else ++x;
      l = min(l, x);
      r = max(r,x);
      k--;
      if (x == 0) 
      {
        z_pos = true;
        ++ans;
        break;
      }
    }
    if(not z_pos) {
      cout << 0 <<'\n';
      continue;
    }
    ll c = 0;
    for (ll i = 0; i < n and k > 0; ++i) {
      if (s[i] == 'L') x--;
      else x++;
      k--;
      if(x == 0) {
        ans += 1;
        c = 1+i;
        break;
      }
    }
    if (c != 0)
      ans += (k / c);
    cout << ans <<'\n';

  }
}


