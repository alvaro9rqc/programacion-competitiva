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

ii f(vector<ii>& prr, int n) {
  int s=2,idx=0;
  for (auto i = 0; i < n-1; i++) {
    int a=0,b=0,d=0;
    for(auto& [l,r]: prr) {
      if(i==r)++a;
      else if(l==i+1)++b;
      else if(r<i or i+1<l) ++d;
    }
    if(b==0 and d == 0) {
      return {0,i};
    } else if(a==0) s=1,idx=i;
  }
  return {s,idx};
}

void solve() {
  int n, m;cin>>n>>m;
  vector<ii> prr(m);
  for(auto& [l,r]: prr) cin>>l>>r,--l,--r;
  auto [s1,i1]=f(prr,n);
  for(auto& [l,r]: prr) l=n-1-l,r=n-1-r,swap(l,r);
  auto [s2,i2]=f(prr,n);
  i2=n-1-i2;
  int xd = 0;
  vi ans(n,-1);
  // dbg(s1);
  // dbg(s2);
  if(s1==2 and s2==2) ans[0]=xd++,ans[n-1]=xd++;
  else if(s1<s2) ans[i1]=xd++,ans[i1+1]=xd++;
  else ans[i2]=xd++, ans[i2-1]=xd++;
  for(auto& i: ans) 
  if(i==-1)i=xd++;
  for(auto& i: ans) cout<<i<<' ';
  cout<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}
