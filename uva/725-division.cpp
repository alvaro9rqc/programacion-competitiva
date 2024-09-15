#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  int a, f, N=1;
  scanf("%d", &N) ;
  while(N) {
    bool s = false;
    for (a = 1234; ( f=a*N ) < 98765; ++a ) {
      int j = 0, tmp = a;
      if (a<10000) ++j;
      while (tmp) {
        j |= (1<< (tmp % 10)); 
        tmp /=10;
      }
      tmp = f;
      while (tmp) {
        j |= (1<< (tmp % 10)); 
        tmp /=10;
      }
      //if (a == 1283) cout << a << ' ' << f<<' '<<j <<'\n';
      if (j == ( (1<<10)-1 )) 
      {
        s = true;
        printf("%.5d / %.5d = %d\n", f, a, N);
      }
    }
    if (!s)printf("There are no solutions for %d.\n", N);
    scanf("%d", &N) ;
    if (N) printf("\n");
  }

  return 0;
}


