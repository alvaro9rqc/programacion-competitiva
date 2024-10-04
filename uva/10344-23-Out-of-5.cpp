#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi v(5);

bool bactraking(int n, int i) {
  if (i == 0) return (n == v[i]);
  bool f = false;
  if (!f  && ((n % v[i]) == 0)) 
  {
    f = bactraking(n/v[i], i-1);
  }
  if (!f) f = bactraking(n -v[i], i-1);
  if (!f) f = bactraking(n + v[i], i-1);
  return f;
}

int main () {
  ios_base::sync_with_stdio(false);
  while (true) {
    for (int i=0; i < 5; ++i) 
      cin >> v[i];
    if (
        v[0] == 0 &&
        v[1] == 0 &&
        v[2] == 0 &&
        v[3] == 0 &&
        v[4] == 0
       ) break;
    bool f = false;
    sort(v.begin(), v.end());
    int x = 1;
    do {
      f = bactraking(23, 4);
      //cout << x++ << '\n';
    } while (next_permutation(v.begin(), v.end()) && !f);
    if (f) cout << "Possible\n";
    else cout << "Impossible\n";
  }
  return 0;
}


