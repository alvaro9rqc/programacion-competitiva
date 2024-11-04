#include <bits/stdc++.h> 
using namespace std;
typedef pair<long long, int> ii;
typedef vector<long long> vi;
typedef vector<ii> vii;

const long long C = 6001;
long long table[11][C+3];

int main () {
  ios_base::sync_with_stdio(false);
  memset(table, 0, sizeof table);
  long long price[] = {1,2,4,10,20,40,100,200,400,1000,2000};
  //caso base
  for (auto i = 0; i < C; ++i) {
    if (i % price[10] == 0) table[10][i] = 1;
    else table[10][i] = 0;
  }
  for (auto i = 9; i >= 0; --i) {
    long long j;
    table[i][0] = 1;
    for (j = 1; j < price[i]; ++j) {
      table[i][j]=0;
    }
    for (j; j < C; ++j) {
      table[i][j] = table[i][j-price[i]] + table[i+1][j];
    }
  }
  double dollar; long long m;
  while (scanf("%lf", &dollar)) {
    if (dollar == 0.0) break;
    m = (long long)(dollar*20);
    printf("%6.2lf %16lld\n", dollar, table[0][m]);
  }
  return 0;
}


