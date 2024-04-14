#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n, k, m;
  scanf("%d", &n);
  while (n--) {
    scanf("%d\n", &k);
    unordered_map <char, int> mapa;
    char key;
    int value;
    while (k--) {
      scanf("%c %d\n", &key, &value);
      mapa[key] = value;
    }
    scanf("%d\n", &m);
    string line;
    long long sum = 0;
    while (m--) {
      getline(cin, line);
      for (char c : line) {
        sum += mapa[c];
      }
    }
    printf("%lld.%.2lld$\n", sum / 100, sum % 100);
    //printf("%lld\n", sum);
    //    123456
  }
  return 0;
}

