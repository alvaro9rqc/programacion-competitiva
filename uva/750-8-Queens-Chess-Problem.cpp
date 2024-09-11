#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int row[8], a,b,lc;

backtraking(int c) {
  if (c == 7) {
    for (int i = 0; i<7;++i) {
      row[c] = i;
      if (bounded() && row[b] == a)
        printf("1 1 5 8 6 3 7 2 4");
    }
  }
  for (int i = 0; i < 6)
}

int main () {
  ios_base::sync_with_stdio(false);
  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &a, &b);
    menset(row, 0,sizeof row);
    backtraking(0);
  }
  return 0;
}


