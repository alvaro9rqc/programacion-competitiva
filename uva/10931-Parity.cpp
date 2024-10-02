#include <bits/stdc++.h> 
using namespace std;
int main () {
  int i, sum;
  while (cin>>i) {
    if (i == 0) break;
    sum = 0;
    for (int j= 0; j < 31; j++) {
      sum += ( (i & (1<<j))==0 )? 0: 1;
      //cout << "xd" << '\n';
    }
    string s= bitset<32>(i).to_string();
    s = s.substr(s.find('1'));
    printf("The parity of %s is %d (mod 2).\n",
        //bitset<32>(i).to_string().c_str(),
        s.c_str(),
        sum);
    //cout << sum%2 << '\n';
  }
  return 0;
}


