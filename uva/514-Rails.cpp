#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin>> n && n) {
    while (true) {
      vector <int> v (n);
      cin >> v[0];
      if(!v[0]) break;
      int m = n-1, i=1;
      while(m--){
        cin>>v[i++];
      }
      stack<int>st;
      m = 0, i = 1;
      while(m<n) {
        if(!st.empty() && st.top() == v[m]) {
          m++;
          st.pop();
        } else {
          if(i>n) break;
          st.push(i++);
        }
      }
      if(st.empty()) cout<<"Yes"<<'\n';
      else cout <<"No" << '\n';
    }
    cout << '\n';
  }
	return 0;
}
