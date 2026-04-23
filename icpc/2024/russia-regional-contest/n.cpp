#include<bits/stdc++.h>
using namespace  std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vl = vector<ll>;
#define rep(i, a, b) for (auto i = a; i != (b); ++i)
#define raya cerr<< "===================="<<endl;
#define sz(x) (int)(x).size()
#define dbg(x) cerr<< #x << " = " << (x) <<endl;

struct Node {
    map<int,int> m;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;cin>>n;
    vector<string> l(n);
    vector<Node> h(1);
    rep(i,0,n)cin>>l[i];
    int xd=1000;
    rep(i,0,n) {
        int x=0;
        rep(j,0,sz(l[i])) {
            auto it = h[x].m.find(l[i][j]);
            if(it==h[x].m.end()) {
                int y = sz(h);
                h[x].m[l[i][j]]=y;
                h.emplace_back();
                x=y;
            } else 
                x=it->second;
        }
        h[x].m[xd]=-1;
    }
    int me=1,mc=0,m=me;
    int x= 0;
    int ans = 0;
    rep(i,0,sz(l[0])) {
        //dbg(m==me);
        //dbg(sz(h[x].m));
        //dbg(ans);
        //for(auto [k,v]: h[x].m) cout<<k<<' '<<v<<'\n';
        if(m==me) {
            ++ans;
            if(sz(h[x].m)==1)m=mc;
        } else {
            if(sz(h[x].m)>1) ++ans,m=me;
        }
        x=h[x].m[l[0][i]];
        //dbg(ans);
        //raya;
    }
    cout<<ans<<'\n';
}

