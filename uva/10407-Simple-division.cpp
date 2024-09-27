#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd( int a, int b ) {
  return b == 0 ? a:gcd(b, a%b);
}

int main () {
  ios_base::sync_with_stdio(false);
  int x;
  while (true) {
    cin >> x; if ( x == 0 ) break;
    vi v;
    int ini = x;
    v.push_back(x-ini);
    cin >> x;
    while (x != 0) {
      v.push_back(x-ini);
      cin >> x;
    }
    int g = gcd(v[0], v[1]);
    for (int i = 2; i < v.size(); ++i) 
      g = gcd(g, v[i]);
    if (g < 0) g *= -1;
    cout << g << '\n';
  }
  return 0;
}


