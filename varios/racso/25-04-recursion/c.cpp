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

int n;

int f(int a, int b) {
  if (a == 1 and b == 1) return 0;
  if (a-b == 1) return b;
  if (a == b or a < 1 or b < 1) return n;
  return 1 + f(max(b, a-b), min(b, a-b) );
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int ans = n;
  for (auto i = 0; i < n; ++i) {
    ans = min(ans, f(n, i));
  }
  cout << ans << '\n';
}


