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

ll n;
vll v;
vector<vll> memo(2, vll(200010, -1));

ll dp(int par, int idx) {
  if(idx == n-2) {
    if (par == 2) return v[n-2]*2+v.back();
    return v[n-2]+2*v.back();
  } else if (idx == n-1) {
    return v.back()*par;
  }
  if(memo[par-1][idx] != -1) return memo[par-1][idx];
  return memo[par-1][idx] = v[idx]*par + max( 
      dp(par % 2 + 1, idx+1), dp(par % 2 + 1, idx + 2)
      );
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  v.assign(n,0);
  for(auto& i: v) {
    cin >> i;
  }
  if(n==1) {
    cout << v.front() <<'\n';
  } else if (n == 2) {
    cout << v[0] + v[1]*2 <<'\n';
  } else {
    cout << max(dp(1,0), dp(1, 1)) <<'\n';
  }
  return 0;
}


