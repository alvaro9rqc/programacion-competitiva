#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,q;cin>>n>>q;
  vi arr(n+1);
  multiset<int> oms;
  for (auto i = 1; i < n+1; i++) cin>>arr[i],oms.emplace(arr[i]);
  for (auto j = 0; j < q; j++) {
    int k;cin>>k;
    vi krr(k);
    for(auto& i: krr) cin>>i, oms.erase(oms.find(arr[i]));
    cout<<(*oms.begin())<<'\n';
    for(auto& i: krr) oms.emplace(arr[i]);
  }
}

