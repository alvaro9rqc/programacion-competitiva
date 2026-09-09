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

string ss;
using iii = tuple<int,int,int>;
vector<iii> pf;
int n,q;

iii f(int l,int r) {
  auto [ar,br,cr] = pf[r];
  auto [al,bl,cl] = pf[l];
  int j1=r,j2=l;
  if(ss[j1] == '0' and ss[j2] == '1') ++cr;
  else if(ss[j1] == '1' and ss[j2] == '1') ++br;
  else if(ss[j1] == '0' and ss[j2] == '0') ++ar;
  return {ar-al,br-bl,cr-cl};
}

void solve() {
  cin>>n>>q;
  cin>>ss;
  pf.assign(n,{0,0,0});
  for(int a=0,b=0,c=0,i=0;i<n;++i) {
    int j2 = i;
    int j1 = (j2-1+n)%n;
    if(ss[j1] == '0' and ss[j2] == '0') ++a;
    else if(ss[j1] == '1' and ss[j2] == '1') ++b;
    else if(ss[j1] == '0' and ss[j2] == '1') ++c;
    pf[i]= {a,b,c};
  }
  for (auto i = 0; i < q; i++) {
    int l,r;cin>>l>>r;
    --l,--r;
    auto [a,b,c]=f(l,r);
    if(a<b) swap(a,b);
    ll ans = 0;
    if(c>= a and c>= b){
      ans=c-a+c-b;
    } else if( a-b > b-c ) {
      int d = (a-c)/2;
      c+=d,a-=d;
      ans+=d + 2*(a-c) + a-b;
    } else {
      ll s = a-c+b-c;
      ans +=s/3;
      if(s%3==1) ans+=3;
      else if(s%3==2) ans+=2;
    }
    cout<<ans<<'\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  // cin>>tt;
  while(tt--) {
    solve();
  }
}

