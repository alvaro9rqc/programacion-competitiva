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

vector<bool>vis;
list<int> l;
vector<vi>g;

void dfs(int i){
  vis[i]=true;
  for(auto& v: g[i]) {
    if (not vis[v]) dfs(v);
  }
  l.push_front(i);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin>>   t;
  while(t--) {
    int n;
    cin >> n;
    g.assign(n,vi());
    for (auto i = 0; i < n; ++i) {
      string b;
      cin >> b;
      for (auto j = i; j < n; ++j) {
        if (b[j]=='1') g[i].push_back(j);
      }
    }
    l.clear();
    vis.assign(n,false);
    for (auto i = 0; i < n; ++i) {
      if (not vis[i]) dfs(i);
    }
    for(auto& e: l) {
      cout << e+1 << ' ';
    }
    cout << '\n';
  }

}


