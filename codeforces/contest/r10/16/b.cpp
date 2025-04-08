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
    string n; cin >> n;
    auto idx = 0u;
    for (auto i = 0u; i < n.size(); ++i) {
      if (n[i] != '0') idx = i;
    }
    ll ans=0;
    for (auto i = 0u; i < idx; ++i) {
      if (n[i]!='0') ans++;
    }
    //cerr << ans << ' '<<idx << '\n';
    ans += ll( n.size()-idx-1 );
    cout << ans << '\n';
  }
}


