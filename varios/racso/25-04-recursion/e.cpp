#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;

vector<string> g;
vector<string> ans;
int n, k; 


void f(int r, int c, int d) {
  if (d == 1) {
    for (auto nr = 0; nr < n; ++nr) {
      for (auto nc = 0; nc < n; ++nc) {
        ans[r+nr][c+nc] = g[nr][nc];
      }
    }
  } else {
    int inc = (int)pow(n, d-1);
    for (auto nr = 0; nr < n; ++nr) {
      for (auto nc = 0; nc < n; ++nc) {
        if (g[nr][nc] == '.') {
          //cerr << nr << " " << nc<<" " << d<<" " << inc << '\n';
          //cerr << r << " " << c<<" " << d<<" " << inc << '\n';
          f(r+nr*inc, c+nc*inc, d-1);
        } else {
          int tr = r+(nr+1)*inc;
          int tc = c+(nc+1)*inc;
          for (auto i = r+nr*inc; i < tr; ++i) {
            for (auto j = c+nc*inc; j < tc; ++j) {
              ans[i][j] = '*';
            }
          }
        }
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ifstream file("input.txt");
  file >> n >> k;
  g.assign(n, "");
  for(auto& s: g) file >> s;
  ans.assign(ll(pow(n,k)), string(ll(pow(n,k)), 'x'));
  f(0, 0, k);
  file.close();
  ofstream f2("output.txt");
  for(auto& s: ans) f2 << s <<'\n';

}


