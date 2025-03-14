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
  int T; cin >> T;
  while(T--) {
    ll n, x, k; 
    cin >> n >> x >> k;
    cout << "-> " << n <<'\n';
    string s; cin >> s;
    unordered_map<ll, ll> st;
    ll x_i = x;
    ll l=x,r=x;
    for(auto& c: s) {
      if (c == 'L') {
        --x;
        if (x < l) l = x;
      } else {
        ++x;
        if (r < x) r = x;
      }
      st[x]++;
    }
    if (x == x_i) {
      if ( st.find(0) == st.end() ) {
        cout << 0 <<'\n';
        continue;
      }
      ll ans = st[0] * (k / n);
      for(auto& c: s) {
        if (c == 'L') --x;
        else ++x;
        if (x == 0) ans++;
      }
      cout << ans <<'\n';
    } else {
      ll g;
      if (x_i <= x) {
        g = 0;
        ll d = x - x_i;
        if (0 < l) {
          cout << 0 <<'\n';
          continue;
        }
        if (r < 0) {
          ll des = 0 - r;
          ll u = des / d + ( des % d != 0?1:0 );
          g -= u*d;
          k -= u*n;
        }
        if (k <= 0) {
          cout << 0 <<'\n';
          continue;
        }
        ll ans = 0;
        for (g; l <= g and k >= n ; g -= d) {
          ans += st[g];
          k -= n;
        }
        if (k > 0 and l <= g) {
          for (ll i = 0; i < k; ++i) {
            if (s[i] == 'L') x_i--;
            else x_i++;
            if ( x_i == g ) ans++;
          }
        }
        cout << ans <<'\n';
      } {
        g = 0;
        ll d = x_i - x;
        if (r < 0) {
          cout << 0 <<'\n';
          continue;
        }
        if (0 < l) {
          ll des = l - 0;
          ll u = des / d + ( des % d != 0?1:0 );
          g += u*d;
          k -= u*n;
        }
        if (k <= 0) {
          cout << 0 <<'\n';
          continue;
        }
        ll ans = 0;
        for (g; g <= r and k >= n ; g -= d) {
          ans += st[g];
          k -= n;
        }
        if (k > 0 and g <= r) {
          for (ll i = 0; i < k; ++i) {
            if (s[i] == 'L') x_i--;
            else x_i++;
            if ( x_i == g ) ans++;
          }
        }
        cout << ans <<'\n';
      }
    }
  }
}


