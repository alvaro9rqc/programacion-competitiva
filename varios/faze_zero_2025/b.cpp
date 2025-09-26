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

int ans = 0;
int N;
vector<vector<pair<int, char>>> g;
vector<bool> vis;
string stk;

void dfs(int v, int deep) {
  if (g[v].size() == 0u) {
    /*
    caso hoja
    factores primos
    probar si se puede dividir hasta encontrar uno
    si es así, ese es la respuesta y actualizo ans
    de lo contrario, la respuesta es 0
     * */
    //cout << stk << ' ' <<  deep <<  '\n';
    int lans = ans +1;
    for (auto inc = lans; (inc<<1) <= deep; ++inc) {
      bool can = true;
      for (auto i = 0; i < inc; ++i) {
        if (stk[i] != stk[i+inc]) {
          can = false; break;
        }
      }
      if (can) ans = inc;
    }
  } else {
    for(auto& [u, e]: g[v]) {
      stk[deep] = e;
      dfs(u, deep+1);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N; 
  g.assign(N,vector<pair<int, char>>());
  vis.assign(N, false);
  stk.assign(N, '.');
  vi ver(N-1);
  string edges;
  for(auto& e: ver) cin >> e, --e;
  cin >> edges;
  for (auto i = 0; i < N-1; ++i) {
    g[ver[i]].emplace_back(i+1, edges[i]);
  }
  dfs(0, 0);
  cout << ans << '\n';
}


