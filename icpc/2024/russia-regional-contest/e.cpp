#include<bits/stdc++.h>
using namespace  std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vl = vector<ll>;
#define rep(i, a, b) for (auto i = a; i != (b); ++i)
#define raya cerr<< "===================="<<endl;
#define sz(x) (int)(x).size();
#define all(x) begin(x), end(x)
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    long double x;
    ll n;cin>>n>>x;
    vector<long double> val(n);
    rep(i,0,n) cin>>val[i];
    sort(val.rbegin(), val.rend());
    long double s=0;
    rep(i,0,n) s+=val[i]/(i+1);
    cout<<(s>=x?"YES":"NO")<<'\n';
}

