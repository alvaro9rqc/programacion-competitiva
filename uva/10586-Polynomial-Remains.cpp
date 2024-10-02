#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  int n, k;
  while (cin >> n >> k) {
    if (n ==-1 && k==-1) break;
    vector<int> a(n+1);
    for (int i = 0; i <= n; i++) cin >> a[i];
    if (k == 0) 
    {
      cout << '0' << '\n';
      continue;
    }
    for (int i = n-k; i >= 0; i--) a[i]-=a[i+k];
    //for (int i = k; i <= n; i++)
      //a[i] += a[i-k]*-1;
    if (k > n) {
      cout << a[0];
      for (int i = 1; i <= n; i++) if (a[i]) cout << ' ' << a[i];
      cout << '\n'; continue;
    }
    cout << a[0];
    for (int i = 1; i < k; i++)
      if (a[i]!=0) 
        cout << ' ' << a[i];
    cout << '\n';
  }
  return 0;
}


