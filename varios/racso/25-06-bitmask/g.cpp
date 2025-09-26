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
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int k;
  cin >> k;
  vi a(k);
  for(auto& e: a) cin >> e;

  for (auto i = 0; i < (1<<k); ++i) {
    int m = 0;
    for (auto j = 0; (1<<j)<= i; ++j) 
      if (i &(1<<j)) m |= 1<<a[j];
    cout << m<<": ";
    for (auto j = 0; (1<<j)<= i; ++j) 
      if (i &(1<<j)) cout << a[j] <<" ";
    cout << '\n';
  }
}


