#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  vector<long> v(32);
  v[0]=1;
  for(int i = 1; i < 32; i++) v[i]=v[i-1]*2;
  string line;
  while (cin >> line) {
    if (line[0] == '0') break;
    long s = 0;
    for (int i = 0; i < line.size(); i ++) {
      s += (long)(line[i]-'0')*(v[line.size()-i]-1);
    }
    cout << s << '\n';
  }
  return 0;
}


