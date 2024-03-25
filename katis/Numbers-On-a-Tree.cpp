#include <bits/stdc++.h> 
using namespace std;
void calc(int & i, char & c) {
  i *= 2;
  switch (c) {
    case 'L':
      i++;
      break;
    case 'R':
      i += 2;
      break;
  }
}
int main () {
  //Well, I am learning about binary heap and Brothers Halim told in 
  //their book that this problem could choose the binary heap indexing 
  int h; char d;
  scanf("%d ", &h);
  string s;
  cin >> s ;
  //priority_queue<int> pq;
  //for (int i = 0; i < (1 << (h + 1)) - 1; i++) {
  //  pq.push(i + 1);
  //}
  int idx = 0;
  for (int i = 0; i < s.size(); i++) {
    calc(idx, s[i]);
  }
  //for (int i = 0; i < idx; i++) {
  //  pq.pop(); 
  //}
  //cout << pq.top() << '\n';
  cout << ((1 << (h + 1)) - 1) - idx << '\n';
  return 0;
}

