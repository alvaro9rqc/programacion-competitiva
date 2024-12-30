#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
map<int, set<int>> mapa;
vector<pair<int,int>> puntos;
map<tuple<int,int,int,int,int>,ll> memo;

ll dp(ll& x, ll& y, int m, ll& fx, ll& fy) {
  if (i >= 7) {
    if (x >= fx or y <= fy) return 0;
  }
  if (i == 8) {
    if (fx - x == y-fy) return 1;
    else 0;
  }
  auto iterator = memo.find({x,y,m,fx,fy});
  if (iterator !=memo.end()) return iterator->second;
  if (m==1) {
    ll sum = 0;
    auto it = mapa.find(x);
    it++;
    bool con, dig; con=dig=true;
    while (it != mapa.end()) {
      if (con and it->second.find(y)!=it->second.end()) {
        sum += dp(it->first, y, m, fx, fy);
        con = false;
      }
      ll dx = it->first - x;
      if (dig and it->second.find(y+dx) != it->second.end()){
        sum += dp(it->first, y+dx, m+1, fx, fy);
        dig = false;
      }
      if (!con and !dig) break;
      it++;
    }
    memo[{x,y,m,fx,fy}] = sum;
    return sum;
  }
  else if (m==2) {
    ll sum = 0;
    auto it1,it2, it = mapa.find(x);
    it1=it2=++it;
    while (it1 != mapa.end()) {
      ll dx = it1->first-x;
      if (it1->second.find(y+dx) != it1->second.end()) {
        sum += dp(it1->first, y + dx, m, fx, fy);
        break;
      }
    }
    auto xd = it2->second.find(y);
    ++xd;
    if (xd != it2->second.end()) 
      sum += dp(x, *xd, m+1, fx, fy);
  }
  else if (m == 3) {
    ll sum = 0;
    auto it = mapa.find(x);
    auto yp = it->second.find(y);
    ++yp;
    if (yp != it->second.end())
      sum += dp(x, *yp, m, fx, fy);
    --it;
    while (it != mapa.end()) {
      ll dx = x - it->first;
      if (it->second.find(y+dx) != it->second.end()) {
        sum += dp(it->first, y+dx, m+1, fx, fy);
        break;
      }
      --it;
    }
    memo[{x,y,m,fx,fy}]= sum;
    return sum;
  }
  else if (m == 4) {
    ll sum = 0;
    auto it1, it2 = mapa.find(x);
    it1 = it2;
    it1--;
    while (it1 != mapa.end()) {
      
    }
  }

}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    mapa[x].insert(y);
    puntos.emplace_back(x, y);
  }
  ll sum = 0;
  for(auto& [x,y]: puntos) {
    sum += dp(x,y, 1,x,y);
  }
  cout << sum<<'\n';
  return 0;
}


