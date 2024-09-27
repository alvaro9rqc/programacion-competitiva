#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<long> fac(21);

string f (string s, long k) {
  if (s.size() == 1) return s;
  return f(s.substr(1), k % fac[s.size()-1]).insert(k/fac[s.size()-1], 1, s.front());
}

int main () {
  ios_base::sync_with_stdio(false);
  fac[0] = 1;
  for (long j = 1; j < 21; ++j) fac[j] = j * fac[j-1];
  int t; 
  cin >> t;
  int i = 0;
  while (i++ < t) {
    string s; long k;
    cin >> s >> k;
    cin >> ws;
    k--;
    cout << "Case " << i << ": "<< f(s, k)<<'\n';
  }
  return 0;
}


