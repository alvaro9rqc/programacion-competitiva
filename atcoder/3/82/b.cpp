#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d; string s; 
  cin >> n >> d >> s;
  int i =0;
  int c=0;
  for (i = n-1; i >= 0; --i) {
    if (s[i] == '@') c++;
    if (c == d) break;
  }
  cout << s.substr(0, i) << string(n -i, '.')<<'\n';
  return 0;
}


