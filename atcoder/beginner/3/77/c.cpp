#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll n, m;

ll dr[] = { -1,-2,-2,-1,1,2, 2, 1 };
ll dc[] = { -2,-1, 1, 2,2,1,-1,-2};

bool valid(int r, int c) {
  return 0 <= r and r < n and 
    0 <= c and c < n;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  set<ii> s;
  ll ans = 0;
  for (ll i = 0; i < m; ++i) {
    ll r, c; cin >> r >> c;
    r--;c--;
    if (s.find({r,c}) == s.end()) {
      ++ans;
      s.emplace(r,c);
    }
    for (int i = 0; i < 8; ++i) {
      ll nr = r + dr[i];
      ll nc = c + dc[i];
      //cout << nr << ' ' << nc << '\n';
      if (valid(nr,nc) and s.find({nr,nc}) == s.end()) {
        ++ans;
        s.emplace(nr,nc);
      }
    }
  }
  cout << n*n - ans << '\n';
  return 0;
}


