#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<string> table;

int movh[] = {-2, -2,  1, -1,  1, -1,  2,  2};
int movv[] = { 1, -1,  2,  2, -2, -2,  1, -1};

int rowrey[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colrey[] = { -1, 0, 1, -1, 1, -1, 0, 1 };


void process(int row, int col) {
  table[row][col]='Z';
  for (auto i = 0; i < 8; ++i) {
    int y = row + movv[i];
    int x = col + movh[i];
    if (
        x >= 0 && x < table[0].size() &&
        y >= 0 && y < table.size()
       ) table[y][x] = 'Z';
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  int t, m, n;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    table.assign(m,string(n,'.'));
    vector<vi> dist(m, vi(n, 0));
    int orow=0,ocol=0;
    int endr=0,endc=0;
    cin >> ws;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        char x; cin >> x;
        if (x == 'Z') process(i, j);
        else if (x == 'A') {
          orow=i;
          ocol=j;
        }
        else if (x =='B'){
          endr=i;
          endc=j;
        }
      }
      cin >> ws;
    }
    table[endr][endc]='B';
    int cost=0;
    bool find = false;
    queue<ii>q;
    q.emplace(orow, ocol);
    while (! q.empty()) {
      auto [row, col] = q.front(); q.pop();
      if (find) break;
      for (auto i = 0; i < 8; ++i) {
        int y = row + rowrey[i];
        int x = col + colrey[i];
        if (
            x >= 0 && x < table[0].size() &&
            y >= 0 && y < table.size() &&
            table[y][x] != 'Z'
           ) 
        {
          if (table[y][x] == 'B') {
            find=true;
            cost=dist[row][col]+1;
            break;
          } else
          {
            dist[y][x] = 1 + dist[row][col];
            table[y][x]='Z';
            q.emplace(y, x);
          }
        }
      }
    }
    if (find) {
      cout << "Minimal possible length of a trip is "<<cost<<'\n';
    } else 
      cout << "King Peter, you can't go now!\n";
  }
  return 0;
}
