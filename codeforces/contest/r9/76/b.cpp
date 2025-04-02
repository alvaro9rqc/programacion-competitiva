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

ll bulbs(ll n){
  return n - ll( sqrt(n) );
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll k; cin >> k;
    ll left=k,right=ll( sqrt(k) );
    right = (right+2)*(right+2);
    while(left<right){
      ll mid = (left+right)/2;
      ll r = bulbs(mid);
      if (r < k) left=mid+1;
      else right=mid;
    }
    cout << right << '\n';
  }
}


