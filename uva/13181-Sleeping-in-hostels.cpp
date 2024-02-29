#include <bits/stdc++.h> 
using namespace std;
int main () {
  char c[500000];
  while (scanf("%s", c) != EOF) {
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    int i = 0;
    //cout << size << '\n';
    while (c[i] != 'X') {
      s1++;
      i++;
    }
    int puntos = 0;
    int lastx = i;
    i++;
    while (c[i] != '\0') {
      if (c[i] == 'X') {
        s2 = (puntos > s2) ? puntos:s2;
        puntos = 0;
        lastx = i;
        i++; continue;
      }
      puntos++;
      i++;
    }
    s3 = i - lastx - 1;

    s2 = (s2 % 2 == 1) ? floor(s2 / 2.0):(s2/2 - 1);
    int max = ((s1 - 1) > s2) ? (s1 - 1):s2;
    max = (max > s3 - 1) ? max:(s3 - 1);
    printf("%d\n", max);
    //printf("1: %d, 2: %d, 3: %d\n", s1, s2, s3);
  }
//  if (c[1000] == '\0')
//    cout << "vacío" << '\n';
  return 0;
}

