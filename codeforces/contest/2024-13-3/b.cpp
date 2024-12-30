#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    unordered_map<char, int> map;
    int n; string s;
    cin >> n >> ws >> s;
    char x = 0;
    int rep  = 0;
    int min = 1000000;
    for(auto& c: s) {
      ++map[c];
      if (map[c] > rep) {
        rep = map[c];
        x = c;
      }
    }
    int y = 0;
    for(int i =0; i< s.size();++i) {
      if (map[s[i]] < min and s[i]!=x) {
        y = i;
        min = map[s[i]];
      }
    }
    s[y]=x;
    cout << s <<'\n';
  }
  return 0;
}


