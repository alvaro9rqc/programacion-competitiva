#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  long t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    vector<bool> v1(n+1, false);
    vector<bool> v0(n+1, false);
    int a, b;a=b=0;
    //cout << n << '\n';
    while (n--) {
      int x,y;
      cin >> x >> y;
      if (y) 
      {
        ++a;
        v1[x] = true;
      }
      else 
      {
        ++b;
        v0[x]=true;
      }
    }
    int l,c; l=c=0;
    for (int i = 0; i< v1.size(); ++i){
      if (v0[i] && v1[i]) ++l;
    }
    for (int i = 1; i < v0.size()-1; ++i) 
    {
      if (v0[i-1] && v0[i+1] && v1[i]) ++c;
      if (v1[i-1] && v1[i+1] && v0[i]) ++c;
    }
    cout << l*(a+b-2) + c << '\n';
  }
  return 0;
}


