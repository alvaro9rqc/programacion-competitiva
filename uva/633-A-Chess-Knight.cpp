#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vector<int>> chess;
int n;

int mr[] = {1,1,-1,-1,2,2,-2,-2,  2,2,-2,-2};
int mc[] = {-2,2,2,-2,-1,1,-1,1, 2,-2,2,-2};

int typ(int i) {
  if (i < 8) return 2;
  if (i < 12) return 3;
  return 5;
}

ii move(int r, int c, int i) {
  if (i < 12)
    return { r+mr[i], c+mc[i] };
  else {
    if (i == 12) {
      return { n-r-1, c };
    } else return { r, n-c-1 };
  }
}

bool valid(int r, int c) {
  return 0<=r and r < n and 0 <= c and c <n;
}

bool same(int i, int j) {
  if (i >= 12 and j >= 12) return true;
  if (8 <= i and i < 12 and 8 <= j and j < 12)
    return true;
  if (0<= i and i < 8 and 0 <= j and j < 8) return true;
  return false;

}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int orr, orc;
  while (cin >> n) {
    if (n == 0) break;
    n = 2*n;
    chess.assign(n, vector<int>(n, 1));
    cin >> orr >> orc;
    orr--; orc--;
    //chess[orr][orc] = false;
    int destr, destc;
    cin >> destr >> destc;
    destr--; destc--;
    int obr, obc;
    while (cin >> obr >> obc) {
      if (obr == 0 and obc == 0) break;
      obr--; obc--;
      chess[obr][obc] = 30;
    }
    queue<tuple<int,int,int>> que;
    que.emplace(orr, orc, -1);
    int level=0;
    int nodes=1;
    int chil = 0;
    bool f = false;
    while (! que.empty()) {
      auto&[r,c, idx] = que.front(); que.pop();
      //cout << r << ' ' << c << '\n';
      if (r == destr and c == destc) {
        f = true;
        break;
      }
      nodes--;

      for (auto i = 0; i < 14; ++i) {
        if (same(idx, i)) continue;
        auto [nr, nc] = move(r, c, i);
        if (valid(nr, nc) and chess[nr][nc] % typ(i) != 0) {
          //cout << nr << ' ' << nc << '\n';
          que.emplace(nr, nc, i);
          chess[nr][nc] *= typ(i);
          chil++;
        }
      }
      if (nodes == 0) {
        nodes= chil;
        chil=0;
        level++;
      }
    }
    if (f) 
      cout << "Result : "<<level <<'\n';
    else cout << "Solution doesn't exist\n";
  }
  return 0;
}


