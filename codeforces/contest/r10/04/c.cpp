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
  ll t; cin  >> t;
  while(t--) {
    ll n; cin >> n;
    string sn = to_string(n);
    cout << n <<"  "; 
    ll idx =2;
    ll dm = 10;
    int si = sn.size();
    for (int i = 1; si - i-1 >= 0; ++i) {
      int j = si-i-1;
      //cout <<": "<<j<<'\n';
      int d = int( '7'- sn[j] );
      if (sn[j] > '7') continue;
      if (d < dm) {
        dm = d;
        idx = i;
      }
    }
    ll s = 0;
    for (auto i = 0; i < idx; ++i) {
      s*=10;
      s+= 9;
    }
    cout << s<<"  ";
    int ans = 0;
    while(true) {
      sn = to_string(n);
      if (sn.find("7") !=string::npos) {
        cout << ans <<'\n';
        break;
      }
      n += s;
      ++ans;
    }
  }
  return 0;
}


