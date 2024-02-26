#include <bits/stdc++.h> 
using namespace std;

bool exist(const vector<int> &v, const int & i) {
  return find(v.begin(), v.end(), i) != v.end();
}

void dfs(vector<vector<int>>& al, vector<bool>& dfs_num, int u) {
  dfs_num[u] = true;
  for (int v : al[u])
    if (!dfs_num[v])
      dfs(al, dfs_num, v);
}

int main () {
  int n;
  char l;
  scanf("%d%*c%*c", &n);
  int pres = 0;
  while (n--) {
    scanf("%c%*c", &l);
    //cout << n << l << ":D"<< '\n';
    vector<vector<int>> al;
    vector<bool> dfs_num;
    int vertices = (int)(l - 'A') + 1;
    al.assign(vertices, vector<int>()); 
    dfs_num.assign(vertices, false);
    char a, b;
    while (scanf("%c", &a) != EOF && (a != '\n')) {
      scanf("%c%*c", &b);
      int v, u;
      v = (int)(a - 'A');
      u = (int)(b - 'A');
      if (!exist(al[v], u)) {
        al[v].emplace_back(u);
        al[u].emplace_back(v);
      }
      //cout << v << u << '\n';
    }
    int componentes = 0;
    for (int i = 0; i < vertices; i++) {
      if (!dfs_num[i]) {
        componentes++;
        dfs(al, dfs_num, i);
      }
    }
    if (n > 0) {
      cout << componentes << "\n\n";
    } else {
      cout << componentes << "\n";
    }
    //for (int i : al[1])
    //  cout << i << "-";
    //cout << '\n';
    //for (int i : al[3])
    //  cout << i << "-";
    //cout << '\n';
    //cout << al[0][0] << '\n';
    //cout << al[arist-1][0];
  }

  return 0;
}

