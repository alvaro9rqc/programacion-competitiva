#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

map<char, char> up;
map<char, char> lef;

int main() {
  up['0'] = '0';
  up['1'] = '1';
  up['2'] = '5';
  up['3'] = '3';
  up['4'] = 'x';
  up['5'] = '2';
  up['6'] = 'x';
  up['7'] = 'x';
  up['8'] = '8';
  up['9'] = 'x';

  lef['0'] = '0';
  lef['1'] = '1';
  lef['2'] = '5';
  lef['3'] = 'x';
  lef['4'] = 'x';
  lef['5'] = '2';
  lef['6'] = 'x';
  lef['7'] = 'x';
  lef['8'] = '8';
  lef['9'] = 'x';
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  string inp; cin >> inp;
  string mir; cin >> mir;
  int z = 0;
  vector<char> nz;
  for (auto i = 0; i < sz(inp); i++) {
    if (mir[i] == 'S') {
      if (inp[i]=='0') ++z;
      else nz.emplace_back(inp[i]);
      continue;
    }
    if (mir[i] == 'D' or mir[i] == 'U') {
      auto c = up[inp[i]];
      if (c == '0') ++z;
      else if(c != 'x') nz.emplace_back(c);
    } else {
      auto c = lef[inp[i]];
      if (c == '0') ++z;
      else if (c != 'x') nz.emplace_back(c);
    }
  }
  sort(all(nz));
  if (sz(nz)) {
    string s;
    s.push_back(nz.front());
    for (auto i = 0; i < z; i++) s.push_back('0');
    for (auto i = 1; i < sz(nz); i++) s.push_back(nz[i]);
    cout << s << '\n';
  } else {
    cout << 0 <<'\n';
  }
}

