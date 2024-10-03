#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi p;
const long lim = 300;

bitset<lim> bs;

int sumDiv(int n) {
  int s = 1;
  for (int i : p) {
    if (i*i > n) break;
    int pri = i;
    int t = 1;
    while(n % i == 0) {
      n /= i;
      t += pri;
      pri *= i;
    }
    s *= t;
  }
  if (n != 1) s *= ( 1 + n );
  return s;
}
//3 - 2 -> 8 / 2 = 4
//5-2 -> 24 / 4 = 6
//1 3 5 15 -> 


int main () {
  ios_base::sync_with_stdio(false);
  bs.set();
  bs[0]=bs[1]=0;
  for (int i = 2; i < lim; ++i) if (bs[i]) {
    for (int j = i*i; j < lim; j+=i) bs[j]=0;
    p.push_back(i);
  }
  printf("PERFECTION OUTPUT\n");
  int n ;
  while (cin >> n) 
  {
    if (n == 0) break;
    int r =sumDiv(n) - n; 
    const char* s;
    if (n == r) s = "PERFECT\n";
    else if (n > r) s = "DEFICIENT\n";
    else s = "ABUNDANT\n";
    printf("%5d  %s", n, s);
  }
  printf("END OF OUTPUT\n");
  
  return 0;
}


