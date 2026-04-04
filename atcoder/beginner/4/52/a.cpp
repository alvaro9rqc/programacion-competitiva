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
  int m,d;cin>>m>>d;
  if(
    (m==1 and d == 7) or
    (m==3 and d == 3) or
    (m==5 and d == 5) or
    (m==7 and d == 7) or
    (m==9 and d == 9) 
  ) cout<<"Yes";
  else cout<<"No";
  cout<<'\n';
}

