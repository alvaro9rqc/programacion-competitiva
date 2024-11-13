#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  long i;
  cin >>i;
  int a = i / 100;
  i %= 100;
  int b = i / 10;
  i %= 10;
  int c = i;
  cout << b << c << a << ' ' << c << a << b << '\n';
  return 0;
}


