#include<bits/stdc++.h>
using namespace  std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vl = vector<ll>;
#define rep(i, a, b) for (auto i = a; i != (b); ++i)
#define raya cerr<< "===================="<<endl;
#define sz(x) (int)(x).size()

ll diff(ll r, ll l, ll d) {
    return r/d - l/d;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, k, c; cin>>n>>k>>c;
    vector<pair<ll,ll>>ds;
    for(int i = 0; i<c; i++) {
        ll t, r; cin>>t>>r;
        ds.push_back({t,r});
    }
    
    for(ll i = k; i<=n; i++) {
       bool f = true;
       for(ll j = 0; j<c; j++) {
           // cout << ds[j].second << " " << diff(i, i-k+1, ds[j].first) << "\n";
         if(ds[j].second!=diff(i, i-k, ds[j].first)) {
            f = false;
            break;
         }      
       }
       if(!f) continue;
       cout << i-k+1 << "\n";
       return 0;
    }
    cout << "-1\n";
    return 0;
}

