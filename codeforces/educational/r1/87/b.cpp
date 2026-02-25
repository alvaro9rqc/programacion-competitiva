#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    string s;cin>>s;
    vector<int>arr;
    ll su = 0;
    for (auto i = 0; i < sz(s); i++) {
      ll x = s[i]-'0'-(i?0:1);
      su+=s[i]-'0';
      arr.emplace_back(x);
    }
    sort(arr.rbegin(),arr.rend());
    ll ans = 0;
    for(auto& i: arr) {
      if (su<10)break;
      ++ans;
      su-=i;
    }
    cout<<ans<<'\n';
  }
}

