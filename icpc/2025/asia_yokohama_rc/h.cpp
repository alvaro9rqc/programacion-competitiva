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

int n, m, k;
vector<string> gri;

bool val2(vi c) {
  return (
    0<=c[0] and c[0]<n and
    0<=c[1] and c[1]<m and
    0<=c[2] and c[2]<n and
    0<=c[3] and c[3]<m and
    0<=c[4] and c[4]<n and
    0<=c[5] and c[5]<m 
  ) and (
    gri[c[0]][c[1]]=='#' and
    gri[c[2]][c[3]]=='#' and
    gri[c[4]][c[5]]=='#' 
  );
}

void pon(vi c) {
  gri[c[0]][c[1]]='.';
  gri[c[2]][c[3]]='.';
  gri[c[4]][c[5]]='.';
}

bool val(int r, int c) {
  //u
  bool can = 1;
  for (auto i = 0; i < k; i++) 
    if (!val2({r+i,c,r+k-1,c+i,r+i,c+k-1})) {can=0;break;}
  if (can){ for (auto i = 0; i < k; i++) 
    pon({r+i,c,r+k-1,c+i,r+i,c+k-1}); return 1;}
  //n
  can=1;
  for (auto i = 0; i < k; i++) 
    if (!val2({r+i,c,r,c+i,r+i,c+k-1})) {can=0;break;}
  if (can){ for (auto i = 0; i < k; i++) 
    pon({r+i,c,r,c+i,r+i,c+k-1}); return 1;}
  //c
  can=1;
  for (auto i = 0; i < k; i++) 
    if (!val2({r+i,c,r,c+i,r+k-1,c+i})) {can=0;break;}
  if (can){ for (auto i = 0; i < k; i++) 
    pon({r+i,c,r,c+i,r+k-1,c+i}); return 1;}
  //
  can=1;
  for (auto i = 0; i < k; i++) 
    if (!val2({r+i,c+k-1,r,c+i,r+k-1,c+i})) {can=0;break;}
  if (can){ for (auto i = 0; i < k; i++) 
    pon({r+i,c+k-1,r,c+i,r+k-1,c+i}); return 1;}
  return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n >> m >> k;
    gri.resize(n);
    for(auto& i: gri) cin >> i;
    bool flag = 1;
    for (auto r = 0; r < n; r++) {
      for (auto c = 0; c < m; c++) 
        if (gri[r][c]=='#') 
          if (!val(r,c)){flag=0;break;}
      if (not flag) break;
    }
    cout << (flag?"yes":"no")<<'\n';
  }
}

