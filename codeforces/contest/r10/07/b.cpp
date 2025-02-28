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
  ll T; cin >> T;
  ll n=1000000ll;
  vll a(n);
  iota(a.begin(), a.end(), 1);
  a[0]=2;
  a[1]=1;
  ll s = 0;
  unordered_set<ll> pro;
  for (ll i = 0; i < n-1; ++i) {
    s += a[i];
    double f = (ll)sqrt(s);
    if(f*f == s) {
      s -= a[i];
      swap(a[i],a[i+1]);
      s += a[i];
      pro.insert(i+1);
    }
  }
  while(T--) {
    ll n; cin >> n;
    if(n == 1) {
      cout << -1 <<'\n';
    } else if(pro.find( n ) != pro.end()) {
      cout << -1 <<'\n';
    }  else {
      for (auto i = 0; i < n; ++i) {
        cout << a[i] <<' ';
      }
      cout <<'\n';
      //ll s = 0;
      //for (auto i = 0; i < n; ++i) {
      //  s+=a[i];
      //  double f = (ll)sqrt(s);
      //  if(f*f == s) {
      //    cout << "oh no: " << s <<' ' <<a[i] <<'\n';
      //  }
      //  //cout << s <<' ';
      //}
    }
  }
}


