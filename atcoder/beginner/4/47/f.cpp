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
  int tt;cin>>tt;
  while(tt--) {
    int n;cin>>n;
    vector<vi> arr(n),adj(n);
    for (auto i = 0; i < n-1; i++) {
      int a, b;cin>>a>>b;--a,--b;
      arr[a].emplace_back(b);
      arr[b].emplace_back(a);
    }
    vector<int> typ(n);
    int black=1,whi=2;
    for (auto i = 0; i < n; i++) {
      if(sz(arr[i])==3)typ[i]=black;
      else if (sz(arr[i])>3)typ[i]=whi;
      // if (typ[i]) {dbg(i);dbg(typ[i]);}
    }
    for (auto i = 0; i < n; i++) {
      if (typ[i]) {
        for(auto& j: arr[i]) if(typ[j])
        adj[i].emplace_back(j);
      }
    }
    vi vis(n);
    auto f = [&](int ori, int id) {
      queue<int> que;
      int furt = ori;
      que.emplace(ori);
      vis[ori]=id;
      while(sz(que)) {
        furt=que.front();
        int l = sz(que);
        for (auto i = 0; i < l; i++) {
          auto u = que.front(); que.pop();
          // dbg(u);
          if (typ[u]==black) continue;
          for(auto& v: adj[u]) {
            // if(typ[v]==black)que.emplace(v);
            if (typ[v]==black or not vis[v]) vis[v]=id, que.emplace(v);
          }
        }
      }
      //second
      int ans = 0;
      int ava = 0;
      que.emplace(furt);
      vis[furt]=-id;
      while(sz(que)) {
        ll l = sz(que);
        for (auto i = 0; i < l; i++) {
          auto u = que.front(); que.pop();
          // dbg(u);
          if (typ[u]==black) {if (ava>=1)continue;}
          for(auto& v: adj[u]) {
            // if (typ[v]==black) que.emplace(v);
            if (vis[v]==id) vis[v]=-id,que.emplace(v);
          } 
          ++ava;
        }
        ++ans;
      }
      return ans;
    };
    int ans = 1;
    int xd = 1;
    for (auto i = 0; i < n; i++) {
      if (typ[i]==black) {
        for(auto& v: adj[i]) if (typ[v]==black)
          ans=max(2,ans);
      } else if (typ[i]==whi and not vis[i]) {
        ans=max(ans,f(i,++xd));
      }
    }
    cout<<ans<<'\n';
  }
}

