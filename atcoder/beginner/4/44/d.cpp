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
  int n;cin>>n;
  vi arr(n); for(auto& i: arr) cin>>i;
  vl del(2*1e5+10);
  for(auto& i: arr) 
  del[0]++,del[i]--;
  ll v = 0;
  ll a =0;
  int i =0;
  vl ans;
  while(1) {
    if (i<sz(del))
      v+=del[i];
    a+=v;
    if(not a)break;
    ans.emplace_back(a%10);
    a/=10;
    ++i;
  }
  reverse(all(ans));
  for(auto& j: ans) cout<<j;
  cout<<'\n';
}

