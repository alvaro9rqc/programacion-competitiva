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
    ll r, c;cin>>r>>c;
    if (r>2) {
        cout<<(c==1?1:-1)<<'\n';
    } else if (r == 2) {
        cout<<((c+1)/2 + (c+1)%2)<<'\n';
    } else if (r==1) {
        cout<<(c/3+(c%3?1:0))<<'\n';
    }

}



