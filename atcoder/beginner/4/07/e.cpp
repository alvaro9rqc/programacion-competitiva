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
  int tt;cin>>tt;
  using pl = pair<ll,ll>;
  while(tt--) {
    int n;cin>>n;
    vl arr(n*2);
    for(auto& i: arr) cin >> i;
    priority_queue<pl> tak;
    priority_queue<pl,vector<pl>, greater<pl>> ava;
    string ans(2*n,0);
    int N =2*n;
    for (auto i = 0; i < N; i++) {
      ava.emplace(arr[i],i);
    }
    for (auto i = 0; i < n; i++) {
      auto [v, id] = ava.top();
      ava.pop();
      ans[id]=')';
    }
    int op = 0;
    for (auto i = 0; i < N; i++) {
      if(ans[i]==0) {
        ans[i]='(';++op;continue;
      }
      tak.emplace(arr[i],i);
      if(op) {--op;continue;}
      auto [v,j] = tak.top(); tak.pop();
      ans[j]='(';
      while(1) {
        auto [v2, j2] = ava.top(); ava.pop();
        if(ans[j2]!=0) continue;
        ans[j2]=')'; break;
      }
      ++op;
    }
    ll rpt = 0;
    for (auto i = 0; i < N; i++) {
      if(ans[i]=='(')rpt+=arr[i];
    }
    cout<<rpt<<'\n';
  }
}

