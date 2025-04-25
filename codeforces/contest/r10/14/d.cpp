#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;



int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt; cin >> tt;
  while(tt--){
    int n; list<char> s;
    cin >> n;
    int rep [] = {0,0,0};
    int m = 0;
    for (int i = 0; i < n; ++i) {
      char c; cin >> c;
      if (c == 'T') ++rep[0], m = max(rep[0], m);
      if (c == 'L') ++rep[1], m = max(rep[1], m);
      if (c == 'I') ++rep[2], m = max(rep[2], m);
      s.push_back(c);
    }
    int ans = 0;
    vi vans;
    auto f = [&] (int idx, char l) {
      bool can = false;
      int i = 1;
      if (rep[idx] == m) return true;
      for (auto it = ++s.begin(); it != s.end(); ++it, ++i) {
        auto a = *(--it);
        auto b = *(++it);
        if ( a != l and b != l) {
          vans.push_back(i++);
          s.insert(it, l);
          ++ans, ++rep[idx];
          if (rep[idx]==m) {can=true; break;}
        }
      }
      return can;
    };
    f(0,'T');
    f(1,'L');
    f(2,'I');
    if (f(0, 'T') and f(1, 'L') and f(2,'I') and ans <= 2*n) {
      for(auto& e: s) cerr << e <<' ';
      cerr<<'\n';

      cout << ans << '\n';
      for(auto& e: vans) {
        cout << e << '\n';
      }
    } else cout << -1 << '\n';


  }
}


