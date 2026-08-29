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

void q(int a, int b, int d) {
  cout<<"? "<<a<<' '<<b<<' '<<d<<endl;
}


void solve() {
  int n;cin>>n;
  int u = 1;
  int d = 1;
  int v = -1;
  for (auto a = 2; a < n+1; a++) {
    q(u,a,d);
    int dr;cin>>dr;
    if(dr)++d,v=a--;
    if(d==n) {
      cout<<"! "<<u<<' '<<v<<' '<<d-1<<endl;
      return;
    }
  }
  for (auto a = 2; a < n+1; a++) {
    if(a==v)continue;
    q(v,a,d);
    int dr;cin>>dr;
    if(dr)++d,u=a--;
    if(d==n) {
      cout<<"! "<<u<<' '<<v<<' '<<d-1<<endl;
      return;
    }

  }
  cout<<"! "<<u<<' '<<v<<' '<<d-1<<endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

