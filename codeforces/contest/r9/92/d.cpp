#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<ll> fac;
const ll LIM = 200002;
bitset<LIM> bs;

vector<bool> visited;
vector<ll> ans;
vector<vector<ll>> gra;
bool flag;

void sieve() {
  bs.set();
  bs[0] = b[1]=0;
  for (ll i = 1; i < LIM; ++i) {
    if (bs[i]) {
      for (ll j = i*i; j < LIM; j+=i) {
        bs[j]=0;
      }
    } else fac.push_back(i);
  }
}

void dfs(ll v) {
  visited[v]=true;
  for(auto& u: gra[v]) {
    if (not flag) return;
    if (not visited[u]) {
      for(auto& e: fac) {
        if (e >= n) {
          flag = false;
          return;
        }
        if (used.find( ans[v] + e ) != used.end()) {
          ans[u] = ans[v]+e;
        }
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    set<ll> used;
    ans.assign(n, -1);
    gra.assign(n, vector<ll>());
    for (auto i = 0; i < n-1; ++i) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      gra[x].push_back(y);
      gra[y].push_back(x);
    }
    flag = true;
    visited.assign(n, false);
    ans[0]=1;
    dfs(0);
    if (flag)
      for(auto& i: visited) {
        cout << i <<' ';
      }
    else cout << -1<<'\n';
    cout << '\n';
  }
  return 0;
}


