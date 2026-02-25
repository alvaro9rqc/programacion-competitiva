#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  int n,k; string s;
  cin >> n >> k >> ws >> s;
  int c = 0;
  int aux = 0;
  for (auto i = 0; i < n; ++i) {
    aux++;
    if (s[i] == 'X') {
      aux = 0;
      continue;
    }
    if (aux == k) 
    {
      aux = 0;
      c++;
    }
  }
  cout << c << '\n';
  return 0;
}


