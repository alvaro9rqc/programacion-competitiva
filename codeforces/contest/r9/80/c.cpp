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
    ll n; cin >> n;
    vector<ii> v(n);
    for(auto& [a,b]: v) {
      cin >> a >> b;
    }
    sort(v.begin(), v.end(), [](auto a, auto b) {
        //int d = 0;
        //d += a.first > b.first?   1:a.first < b.first? -1:0;
        //d += a.first > b.second?  1:a.first < b.second? -1:0;
        //d += a.second > b.first?  1:a.second < b.first? -1:0;
        //d += a.second > b.second? 1:a.second < b.second? -1:0;
        //return d <=0;
        return (b.first + b.second) > (a.first + a.second);
        });
    for(auto& [a,b]: v) {
      cout << a <<' ' << b <<' ';
    }
    cout << '\n';
  }
  return 0;
}


