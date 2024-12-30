#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<string> d1;
vector<string> d2;
int n; 
// 1 2 -> n-1, 1
// 1, 2 -> n, n -2
// 1, 2 -> 2, n
void rot(int lay, int deg) {
  if (deg == 1) {
    for (auto j = lay; j <= n-lay; ++j) {
      d1[j][lay] = d2[n - lay][j];
      d1[n-lay][j] = d2[n-j][n-lay];
      d1[j][n-lay]= d2[lay][j];
      d1[lay][j] = d2[n-j][lay];
    }
  } else if (deg == 2) {
    for (auto j = lay; j <= n-lay; ++j) {
      d1[n-lay][j] = d2[lay][n-j];
      d1[j][n-lay] = d2[n-j][lay];
      d1[lay][j] = d2[n-lay][n-j];
      d1[j][lay] = d2[n-j][n-lay];
    }
  } else if (deg == 3) {
    for (auto j = lay; j <= n-lay; ++j) {
      d1[n-lay][j] = d2[j][lay];
      d1[j][n-lay] = d2[n-lay][n-j];
      d1[lay][j] = d2[j][n-lay];
      d1[j][lay] = d2[lay][n-j];
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  d1.resize(n);
  d2.resize(n);
  for (auto i = 0; i < n; ++i) {
    cin >> d1[i];
  }
  d2 = d1;
  int rotate=0;
  int lim = n/2;
  n--;
  for (auto i = 0; i < lim; ++i) {
    rot(i, rotate+1);
    //for(auto& s: d1) {
    //  cout << s << '\n';
    //}
    //cout << '\n';
    rotate = (rotate +1) % 4;
  }
  for(auto& s: d1) {
    cout << s <<'\n';
  }
  cout << '\n';
  return 0;
}


