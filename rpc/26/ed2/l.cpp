#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vl = vector<ll>;
#define raya cerr<<"===================="<< endl;
#define dbg(x) cerr<< #x << " = " << (x) << endl;
#define rep(i, a, b) for(auto i = a; i != (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

using lll=tuple<ll,ll,ll>;

struct KK {
    bool operator ()(const lll & tu1, const lll & tu2) const {
        auto [t1,v1,id1] = tu1;
        auto [t2,v2,id2] = tu2;
        return make_tuple(t1,v1) < make_tuple(t2,v2);
    }
};

ll n,m,capacidad;
vector<vl> adj;
vl vel,vis;
vl spw,cap;
vector<bool> isch;
using pl = pair<ll,ll>;
vector<pl> tel;
set<pl> orden;
ll t_c;
ll meta;


void dfs(ll u, ll d, ll cp) {
    //dbg(u);
    //dbg(cp);
    vis[u]=d;
    tel[u]={d-vis[cp], cp};
    if (isch[u]){
        cp=u;
        orden.emplace(-d, u);
    }
    for(auto& v : adj[u]) {
        if(vis[v] == -1)
            dfs(v, d+1, cp);
    }
}





int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    //phase1
    cin>>n>>m>>capacidad;
    adj.resize(n);
    rep(i,0,n-1){
        int a,b;cin>>a>>b;--a,--b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    vel.resize(m);
    spw.resize(m);
    rep(i,0,m){
        ll c, v;cin>>c>>v;--c;
        vel[i]=v;
        spw[i]=c;
    }
    cin>>meta,--meta;
    cin>>t_c;
    isch.assign(n,0);

    rep(i,0,t_c){
        ll x;cin>>x;--x;
        isch[x]=1;
    }
    vis.assign(n,-1);
    cap.assign(n,capacidad);
    tel.resize(n);
    tel[meta]={0,meta};
    dfs(meta, 0, meta);
    //phase2
//    for(int i=0; i<tel.size(); i++) {
//        cout << tel[i].first << " " << tel[i].second << "\n"; 
//    }
    //raya;
    vector<set<lll,KK>> pues(n);
    rep(i,0,m) {
        auto [d, c] = tel[spw[i]];
        if(isch[spw[i]]) cap[spw[i]]--;
        pues[c].emplace(vel[i]*d,vel[i],i);
    }
    //auto [v1,v2,v3] = *(pues[0].begin());
    //dbg(v1);
    //dbg(v2);
    //dbg(v3);
    for(auto& [dc, c]:orden) {
        if(c==meta)break;
        int i = 0;
        auto [dcp, cp] = tel[c];
        for(auto[t, v, icar]:pues[c]) {
            if(i>=cap[c]) break;
            ++i;
            pues[cp].emplace(t+dcp*v, v, icar);
        }
    }
    vector<ll> ans(m,-1);
    for(auto[t, v, icar]:pues[meta]) {
        ans[icar]=t;
    }
    rep(i,0,m) {
        cout<<ans[i]<<'\n';
    }
}



