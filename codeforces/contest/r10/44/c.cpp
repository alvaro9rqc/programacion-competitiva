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
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vi dis(n);
    vi id(n);
    iota(all(id), 0);
    //distancias
    for (auto i = 0; i < n; ++i) {
      cout <<"? "<< i+1 <<' '<<n<<' ';
      for(auto& e: id) cout << e+1 <<' ';
      cout <<endl;
      cin >> dis[i];
    }
    //ordenar
    sort(id.begin(), id.end(), [&dis](const int& a, const int& b){
        return dis[a] < dis[b];
        });
    //armar
    vi path = {id.back()};
    int md = dis[id.back()];
    int i = n-1;
    while(sz(path) < md) {
      //cout <<"gaa\n";
      auto ori = id[i];
      for (auto j = i-1; j >= 0; --j) {
        auto de = id[j];
        if (dis[de] == dis[ori]-1) {
          cout <<"? "<< ori+1 << ' ' << 2 <<' '<<ori+1<<' '<<de+1<<endl;
          int x; cin >> x;
          if (x == 2) {
            path.emplace_back(de);
            i = j;
            break;
          }
        } else continue;
      }
    }
    cout << "! "<<sz(path)<<' ';
    for (i = 0; i < sz(path); ++i) {
      cout << path[i]+1<<' ';
    }
    cout <<endl;
  }
}


