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
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int H, W; cin >> H >> W;
  vector<string> g(H);
  for(auto& s: g) {
    cin >> s;
  }
  int dow = W, up=0, left = H, right=0;
  for (auto r = 0; r < H; ++r) {
    for (auto c = 0; c < W; ++c) {
      if(g[r][c] == '#') {
        if(r > up) up=r;
        if(r < dow) dow = r;
        if(c < left) left = c;
        if(c > right) right = c;
      }
    }
  }
  //printf("%d %d %d %d\n", left, right, up, dow);
  for (auto c = left; c <= right; ++c) {
    for (auto r = dow; r <= up; ++r) {
      if(g[r][c] == '.') {
        cout << "No\n"; return 0;
      }
    }
  }
  cout << "Yes\n";
  return 0;
}


