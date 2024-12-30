#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t>>ws;
  while (t--) {
    string s; cin >> s;
    int sum = 0;
    vector<int> mul(5,0);
    for(auto& c: s) {
      int n = (int)( c - '0' );
      sum+=n;
      if (n == 2) mul[2]++;
      else if (n==3)mul[3]++;
    }
    if (sum %9==0) {
        //cout << "xx";
      cout << "YES\n";continue;
    }
    int add=0;
    for (auto i = 0; i <= mul[2]; ++i) {
      add = 2*i;
      if (( sum + add )%9==0 ) {
        cout << "YES\n";
        goto label;
      } else {
        int add2;
        for (auto j = 0; j <= mul[3]; ++j) {
          add2 = 6*j;
          //cout << "-> "<<add2 << "-> "<<sum<<'\n';
          if ((sum +add+ add2) % 9 == 0) {
            cout << "YES\n"; 
            goto label;
          }
        }
      }
    }
    cout << "NO\n";
    label:
    add;
  }
  return 0;
}


