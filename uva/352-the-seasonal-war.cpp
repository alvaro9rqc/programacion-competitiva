#include <bits/stdc++.h> 
using namespace std;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void floodfill(int r, int c, int t, vector< vector<bool>> &graph) {
  if ( (r < 0) || (r >= t-1) ) return; //remember idx based 0
  if ( (c < 0) || (c >= t-1) ) return;
  if (graph[r][c]) { 
    graph[r][c] = 0;
    for (int i = 0; i < 8; ++i)
      floodfill(r+dr[i], c+dc[i], t, graph);
  }
}

int main () {
  int cases = 0;
  int x; 
  while (cin >> x) {
    cout << "case: " << x << '\n';
    ++cases;
    vector< vector<bool> > graph(x, vector<bool>(x));
    int dummy;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < x; j++) {
        scanf("%d", &dummy); graph[i][j] = dummy;
      }
    }
    int teams = 0;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < x; j++) {
        if (graph[i][j]) {
          ++teams;
          floodfill(i, j, x, graph);
        }
      }
    }
    printf("Image number %d contains %d war eagles.\n", cases, teams);
    //cout << graph[0][2] << '\n'; --all rigth
  }
  return 0;
}

