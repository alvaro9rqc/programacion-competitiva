#include <bits/stdc++.h> 
using namespace std;
int main () {
  string l;
  int tam = (int) ('z' - 'A' + 1);
  //for (int i = 0; i < tam; i++) {
  //  cout << (char) i + 'A' << " "; 
  //}
  //cout << '\n';
  while (getline(cin, l)) {
    int fre [tam] = {0};
    int max = 0;
    string lista;
    for (int i = 0; i < l.size(); i++) {
      int idx = (int) l[i] - 'A';
      if (idx < 0 || idx > tam - 1) continue;
      //cout << idx << " ";
      fre[idx] ++;
      if (fre[idx] > max) max = fre[idx];
    }
    string ans;
    for (int i = 0; i < tam; i++) {
      if (fre[i] == max) {
        ans.push_back(i + 'A');
      } 
    }
    cout << ans << " "<< max << '\n';
  }
  return 0;
}

