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
    ll n, m, x; cin>>n>>x>>m;
    vl arr(2*n+5);
    for(int i = 0; i<m; i++) {
        ll r; cin>>r;
        arr[2*r]++;
    }
    ll sum1 = 0;
    for(int i = 1; i<=2*n+1; i+=2) {
        if(i==x*2-1) break;
        sum1+=arr[i+1];
    }
    ll sum2 = 0;
    for(int i = n*2-1; i>=1; i-=2) {
        sum2+=arr[i+1];
        if(i==x*2-1) break;
    }
    cout << min(sum1,sum2) << "\n";
}



