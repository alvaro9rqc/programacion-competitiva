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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, m; cin>>n>>m;
    vector<string>sts, nds;
    for(int i = 0; i<n; i++) {
        string s; cin>>s;
        sts.push_back(s);
    }
    for(int i = 0; i<n; i++) {
        string s; cin>>s;
        nds.push_back(s);
    }
    ll x; cin>>x;
    auto diffi = [&](string a, string b) {
        ll h1 = stoll(a.substr(0,2)), m1 = stoll(a.substr(3,2)), s1 = stoll(a.substr(6,2));
        ll h2 = stoll(b.substr(0,2)), m2 = stoll(b.substr(3,2)), s2 = stoll(b.substr(6,2));
        ll t1 = h1*3600 + m1*60 + s1;
        ll t2 = h2*3600 + m2*60 + s2;
        if(t1<=t2) {
            return t2-t1;
        }else {
            return ll(1e9);
        }
    };
    ll mini = 1e9;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            ll d = diffi(sts[i], nds[j]);
            if(d<x) continue;
            mini = min(d, mini);
        }
    }
    cout << (mini==ll(1e9) ? -1 : mini) << "\n";

}



