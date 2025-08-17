#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
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
    int n, k; cin >> n >>k;
    vi arr(n); 
    for(auto& e: arr) cin >> e;
    if (k == 1) {cout << "yes\n"; continue;}
    --k;
    vi cop = arr;
    sort(all(cop));
    //cerr << "gaa\n";
    //for(auto& e: cop) cerr << e <<' ';
    //cerr << "gaa\n";
    set<int> s;
    for (auto i = 0; i < k; ++i) {
      s.insert(cop[i]);
    }
    int pass = 0;
    int ele = cop[k-1];
    for (auto i = k; i < n and cop[k-1] == cop[i]; ++i) ++pass;
    cop.clear();
    for(auto& e: arr) {
      if (s.count(e)) cop.emplace_back(e);
    }
    bool can = 1;
    for (auto i = 0, j = sz(cop)-1; i < j; ++i,--j){
      if (cop[i] !=cop[j]) {
        //dbg(arr[i]);
        //dbg(arr[j]);
        if (not pass) {can = 0; break;}
        if (cop[i] ==ele) {++j; --pass; continue;}
        if (cop[j] ==ele) {--i; --pass; continue;}
        can = 0; break;
      }
    }
    cout << (can? "yes":"no") << '\n';
  }
}


