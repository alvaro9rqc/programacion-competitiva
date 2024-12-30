#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

unordered_map<int, char> d;
void erase(int x) {
  int dx = ( 'A' - d[x] );
  x += dx;
  d.erase(x);
  d.erase(x+1);
  d.erase(x+2);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int ans = 0;
  for (auto i = 0; i < n-2; ++i) {
    //cout << s[i]<<s[i+1]<<s[i+2]<<'\n';
    if (s[i] == 'A' and s[i+1] == 'B' and s[i+2] == 'C') {
      ans += 1;
      d[i] = 'A';
      d[i+1] = 'B';
      d[i+2] = 'C';
    }
  }
  for (auto _ = 0; _ < q; ++_) {
    int x;
    char c;
    cin >> x >> c;
    x--;
    if (s[x] == c) {
      goto label;
    }
    s[x] = c;
    if ( d.find(x) != d.end() ) {
      ans--;
      erase(x);
    } 
    if (s[x] == 'A' or s[x]=='B' or s[x]=='C') {
      int dx = 'A' - s[x];
      x += dx;
      if (
          s[x] == 'A' and
          s[x+1] == 'B' and
          s[x+2] == 'C' 
         ) {
        ans++;
        d[x] = 'A';
        d[x+1] = 'B';
        d[x+2] = 'C';
      }
    }
label:
    cout << ans<<'\n';
  }
  return 0;
}
