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
  while(t--) {
    string n;
    cin >> n;
    ll nl = stroll(n);
    int ans;
    {
      int d = (int)( n.back() - '0' );
      if (d < 7) d+= 10;
      ans = d-7;
    }
    for (auto i = n.end()-2; i >= n.begin(); --i) {
      int d =(int)(*i-'0');
      ans = min
    }
  }
}


