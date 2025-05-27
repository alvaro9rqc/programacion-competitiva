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

vi memo(1e6 + 12, -1);

int f(int n) {
  if (memo[n] != -1) return memo[n];
  if (n >= 101) return memo[n] = n -10;
  return memo[n] =  f( f(n+11) );
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; 
  while(cin >> n) {
    if (n == 0) break;
    cout << "f91("<< n <<") = " << f(n) << '\n';
  }
}


