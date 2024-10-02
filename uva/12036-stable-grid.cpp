#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    bool v = true;
    vector<int> f (101, 0);
    cin >> n;
    for(int j=0; j < n*n; j++) {
      int num;
      cin >> num;
      //cout << n << "- " << num <<'\n'; 
      if( ++f[num] > n ) {
        v = false; 
      }
    }
    //cout << n<<'\n';
    if (v) cout << "Case " << i+1 << ": " << "yes\n";
    else cout << "Case " << i+1 << ": " << "no\n";
  }
  return 0;
}


