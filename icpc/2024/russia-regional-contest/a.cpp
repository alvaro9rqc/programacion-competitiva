#include<bits/stdc++.h>
using namespace  std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vl = vector<ll>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int x;cin>>x;
    vl arr(x); for(auto &a: arr) cin>>a;
    vl ans;
    for(int i = 0; i<x-1; i++) {
        if(arr[i]<arr[i+1]) {
            ans.push_back(-1);
        }else {
            ans.push_back(1);
        }
    }
    ll cnt = 0;
    for(int i = 0; i<x-2; i++) {
        if(ans[i]!=ans[i+1]) cnt++;
    }
    cout << (cnt==1 ? "YES" : "NO") << "\n";
}
