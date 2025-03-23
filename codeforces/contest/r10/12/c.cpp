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
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;
using tupla = tuple<int,int,int>;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while(q--) {
    set<tupla> no_used;
    set<tupla> used;
    no_used.emplace(1,1,1);
    int n;
    cin >> n;
    auto drop = [&no_used, &used]() {
      auto t = no_used.begin();
      auto [d,x,y] = *t;
      cout << x << ' '<< y<<'\n';
      no_used.erase(t);
      used.emplace(d+1,x+1,y);
      used.emplace(d+1,x,y+1);
      used.emplace(d+4,x+1,y+1);
      no_used.emplace(d+3, x+3, y);
      no_used.emplace(d+3, x, y+3);
    };
    //auto pass_u = [&no_used, &used] {

    //};
    for (auto i = 0; i <n ; ++i) {
      int g;cin>>g;
      if (g == 0) {
        drop();
      } else {
        if (used.size() == 0) {
          drop();
        } else {
          auto tused = *used.begin();
          auto tno = *no_used.begin();
          if(tused < tno) {
            auto [d, x,y]=tused;
            cout << x << ' '<< y<<'\n';
            used.erase(tused);
          }
          else drop();
        }
      }
    }
  }
}


