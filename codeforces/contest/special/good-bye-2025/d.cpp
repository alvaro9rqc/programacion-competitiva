#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n, m; 
    cin >> n >> m;
    vector<pair<ll,int>> arr; 
    for (auto i = 1; i < n+1; i++) {
      int x;cin>>x;
      arr.emplace_back(x,i);
    }
    sort(all(arr));
    if (m == 0) {
      bool can = 0;
      ll s = 0;
      int i;
      for (i = n-2; i >=0; i--)   {
        s+=arr[i].first;
        if (s>= arr.back().first) {can=1;break;}
      }
      if (not can) {cout <<"-1\n"; continue;}
      cout << (n-1)<<'\n';
      for (auto j = 0; j < i; j++) 
        cout << arr[j].second <<' '<<arr[j+1].second<<'\n';
      for (auto j = i; j < n-1; j++) 
        cout << arr[j].second <<' '<<arr[n-1].second<<'\n';
    } else {
      if (m>n/2) {cout << "-1\n";continue;}
      int i;
      cout << (n-2*m + m)<<'\n';
      for (i = 0; i < n-2*m; i++) 
        cout << arr[i].second <<' '<<arr[i+1].second<<'\n';
      for (auto j = 0; j < m; j++,i+=2) 
        cout << arr[i+1].second<<' '<<arr[i].second<<'\n';
    }
  }
}

