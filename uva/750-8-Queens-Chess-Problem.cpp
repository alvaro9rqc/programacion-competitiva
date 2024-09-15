#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int row[8], a,b,lc;

void p() {
  printf("%2d      %d %d %d %d %d %d %d %d\n",
      ++lc,
      1+row[0],
      1+row[1],
      1+row[2],
      1+row[3],
      1+row[4],
      1+row[5],
      1+row[6],
      1+row[7]
      );
}

bool bounded(int c) {
  for (int i = 0; i < c; ++i) 
    if (
        (row[i] == row[c]) || 
        (abs(i-c) == abs(row[i] - row[c]))
       )
      return false;
  return true;
}

void backtraking(int c) {
  if (c == 7) {
    for (int i = 0; i<8;++i) {
      row[c] = i;
      if (bounded(c) && row[b] == a)
        p();
      //else if (b == a && a == 7) printf("%d %d\n", row[b], row[0]);
    }
    return;
  }
  for (int i = 0; i < 8; ++i) {
    row[c] = i;
    if (bounded(c)) backtraking(c+1);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &a, &b); --a;--b;
    memset(row, 0,sizeof row);
    lc=0;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    backtraking(0);
    if (t) printf("\n");
  }
  return 0;
}
