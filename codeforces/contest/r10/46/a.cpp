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
    int a, b, c ,d ;
    cin >> a >> b >> c >> d;
    c-=a;
    d-=b;
    if (a<b) swap(a,b);
    if (c<d) swap(c,d);
    //if (b == 0 or d == 0) {
    //  cout << ((a>2 or c>2)?"no":"yes")<<'\n';
    //  continue;
    //}
    int x = a / (b+1) + ((a%(b+1))?1:0);
    int y = c / (d+1) + ((c%(d+1))?1:0);
    //dbg(x);
    //dbg(y);
    //if (b+1<=a) x+=(a%(b+1))>0 ;
    //if (d+1<=c) y+= (c%(d+1))>0 ;
    cout << ((x >= 3 or y>=3)?"no":"yes")<<'\n';
  }
}


