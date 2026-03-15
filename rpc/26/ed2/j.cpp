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
    ll n;cin>>n;
    map<ll,ll> omp;
    rep(i,0,n) {
        ll x;cin>>x;
        omp[x]++;
    }
    if(omp.count(3) or omp.count(1) or omp.count(7)) {
        cout<<"1\n";
    } else if (omp.count(5)) {
        if (omp.count(2) or omp.count(6) or omp.count(8) or omp.count(4)) cout<<"1\n";
        else cout<<n<<'\n';
    } else cout<<n<<'\n';
}

