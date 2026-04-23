#include<bits/stdc++.h>
using namespace  std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vl = vector<ll>;

#define rep(i, a, b) for (auto i = a; i != (b); ++i)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;cin>>n;
    ll s=0;
    cout<<n<<endl;
    rep(i, 1, n+1) {
        cout<<i <<' '<<i<<endl;
        s+=i*500;
    }
    ll x;cin>>x;
    cout<<"! "<<x-s<<endl;
}

