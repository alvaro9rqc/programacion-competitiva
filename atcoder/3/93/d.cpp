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
  int n; cin >> n;
  string s; cin >> s;
  int wl=1,wr=1,l=-1,r;
  int ones =0;
  for (auto i = 0; i < n; ++i) {
    if(s[i] == '1') {
      if(l==-1) l = i;
      else r = i;
      ones++;
    }
  }
  if (ones == 1) 
  {
    cout << 0 <<'\n';
    return 0;
  }
  ll ans = 0;
  while(r - l > 1) {
    if (wl >= wr) {
      if(s[r-1] == '1') 
      {
        wr++;
      }
      else {
        ans += wr;
      }
      r--;
      continue;
    }
    else {
      if(s[l+1] == '1') {
        wl++;
      } else {
        ans += wl;
      }
      l++;
      continue;
    }
  }
  cout << ans <<'\n';
  return 0;
}


