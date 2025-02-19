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

int n,k;  
string s;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n>>k;
  cin >> s;
  sort(s.begin(), s.end());
  ll ans = 0;
  do {
    bool es=false;
    for(int i = k-1; i < n; ++i) {
      es = true;
      for(int r=i, l=i-k+1; l < r; ++l,--r) 
        if(s[l] != s[r]) { es=false; break; }
      if(es) break;
    }
    if(es) continue;
    ++ans;
  } while(next_permutation(s.begin(), s.end()));
  cout << ans <<'\n';
}


