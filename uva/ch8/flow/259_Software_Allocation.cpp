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

int n; 
vector<vi> mtx;
vector<vi> adj;
int src = 38;
int tgt = 39;

inline int pos(char x) {
  return int(x - 'A') + 9;
}

int bfs(int s, int t, vi& parent) {
  fill(all(parent), -1);
  parent[s]=-2;
  queue<ii> q;
  q.emplace(s,n);
  while(sz(q)) {
    auto [cur,flow] = q.front(); q.pop();
    for(auto& next: adj[cur]) {
      if (parent[next] == -1 and mtx[cur][next]) {
        parent[next] = cur;
        int new_flow = min(flow, mtx[cur][next]);
        if (next == t) return new_flow;
        q.emplace(next, new_flow);
      }
    }
  }
  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  vi parent(40);
  int new_flow;
  while((new_flow = bfs(s, t, parent))) {
    //dbg(new_flow);
    flow +=new_flow;
    int cur = t;
    while(cur!=s) {
      int p = parent[cur];
      mtx[p][cur] -=new_flow;
      mtx[cur][p] += new_flow;
      cur = p;
    }
  }
  return flow;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  //cin.exceptions(cin.failbit);
  string s;
  while(not cin.eof()) {
    n = 0;
    int m = 9;
    adj.assign(40, vi());
    mtx.assign(40, vi(40, 0));
    for (auto i = 0; i < 10; i++) 
      adj[i].emplace_back(tgt), mtx[i][tgt]=1, 
        adj[tgt].emplace_back(i);
    string abc;
    while(not cin.eof()) {
      getline(cin, s);
      //cout << s <<"===\n";
      if (sz(s) == 0) break;
      ++m;
      abc.push_back(s[0]);
      int id = m;
      mtx[src][id] = int(s[1]-'0');
      n+=s[1]-'0';
      adj[src].emplace_back(id);
      adj[id].emplace_back(src);
      for (auto i = 3; i < sz(s)-1; i++) {
        mtx[id][s[i]-'0']=1;
        adj[id].emplace_back(s[i]-'0');
        adj[s[i]-'0'].emplace_back(id);
      }
    }
    if (n == maxflow(src, tgt)) {
      for (auto i = 0; i < 10; i++) {
        bool asg = 0;
        for(auto& v: adj[i]) {
          if (mtx[v][i]==0 and v != tgt) {
            cout << abc[v-10];
            asg = 1;
            break;
          }
        } 
        if (not asg) cout << '_';
      }
    } else {
      cout << "!";
    }
    cout << '\n';
  }
}

