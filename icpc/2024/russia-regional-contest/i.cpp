#include<bits/stdc++.h>
using namespace  std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vl = vector<ll>;
#define rep(i, a, b) for (auto i = a; i != (b); ++i)
#define raya cerr<< "===================="<<endl;
#define sz(x) (int)(x).size()
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n; cin>>n;
    vector<vl>G(n+1);
    for(int i = 0; i<n+2; i++) {
        ll u, v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll st = -1;
    for(int i = 1; i<=n; i++) {
        if(G[i].size()==4) {
            st = i;
            break;
        }
    }

    vector<bool>vis(n+1);
    vector<vl>paths;
    vl path;
    auto dfs = [&](auto&&self, ll u, ll p, bool is_head)->void {
        vis[u] = true;
        path.push_back(u);
        for(auto v: G[u]) {
            if(v==p) continue;
            if(v==st) {
                path.push_back(v);
                paths.push_back(path);
                path.pop_back();
            }
            if(vis[v]) continue;
            self(self, v, u, is_head||(G[v].size()==3));
        }
        path.pop_back();
    };
    dfs(dfs, st, -1, false);
    vl ans(3, 0);
    for(int i = 0; i<2; i++) {
        bool is_head = false;
        ll cnt = 0;
        for(int j = 0; j<paths[i].size(); j++) {
            if(G[paths[i][j]].size()==3) {
                is_head = true;
            }
        }

        if(!is_head) {
            ans[2] = sz(paths[i])-1;
        }else {
            ll cnt = 0;
            for(int j = 0; j<paths[i].size(); j++ ){
                cnt++;
                if(G[paths[i][j]].size()==3) break;
            }
            for(int j = sz(paths[i])-1; j>=1; j--) {
                cnt++;
                if(G[paths[i][j]].size()==3) break;
            }
            ans[1] = cnt-1;
        }
    }
    ans[0] = n+2-(ans[2]+ans[1]-1);
    for(auto x: ans) {
        cout << x << " ";
    }
    cout << "\n";
    //for(auto x: paths) {
        //for(auto a: x) {
            //cout << a << " ";
        //}
        //cout << "\n";
    //}

}

