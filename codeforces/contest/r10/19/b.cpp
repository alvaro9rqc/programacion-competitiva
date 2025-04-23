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
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    char last = '0';
    int c1=0,c0=0;
    for(auto& c: s) {
      if (c=='1')++c1;
      else ++c0;
      if (c == last) ++ans;
      else ans+=2, last=c;
    }
    if (c0 == n or c1 == n) cout << ans << '\n';
    else {
      // para 101
      int l=0, r=n-1;
      while(l<r){
        if (s[l]=='0') ++l;
        if (s[r]=='0') --r;
        if (s[r]=='1' and s[l]=='1') break;
      }
      bool f = false;
      for (auto i = l; i <= r; ++i) {
        if (s[i]=='0') {
          f=true;
          break;
        }
      }
      if (f) cout << ans - 2 << '\n';
      else 
      {
        if (s.front() == '0' and s.back()=='1') cout << ans<<'\n';
        else cout << ans -1 << '\n';
      }

    }
  }
}


