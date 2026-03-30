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

const char op='(';
const char cl=')';

tuple<int,int,int> f(string& s) {
  int n=sz(s);
  vi val(sz(s));
  stack<int> stk;
  for (auto i = 0; i < n; i++) {
    if(s[i]==op) stk.emplace(i);
    else {
      val[i]=stk.top();
      stk.pop();
    }
  }
  for (auto i = 0; i < n-1; i++) {
    if(s[i]==op and s[i+1]==cl) {
      val[i]=1;
      int l=i-1,r=i+2;
      while(l>=0 and s[r]==cl and val[r]==l) {
        val[l]=val[l+1]+1;
        val[l+1]=-1;
        r++;
        l--;
      }
    }
  }
  int caj =0;
  int l=0,r=n-1;
  // dbg(val[l]);
  // dbg(val[r]);
  while(val[l]==0 and val[r]==l) {
    ++caj;
    l++,r--;
  }
  int one=0, deg=0;
  for (auto i = l; i < r+1; i++) {
    if(s[i]==cl)continue;
    if(val[i]==0) deg++;
    else if(val[i]>0)deg+=val[i]-1,one++;
  }
  return {caj,one,deg};
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n;cin>>n;
    string s1,s2;cin>>s1>>s2;
    auto t=f(s1);
    // dbg(get<0>(t));
    // dbg(get<1>(t));
    // dbg(get<2>(t));
    t=f(s2);
    // dbg(get<0>(t));
    // dbg(get<1>(t));
    // dbg(get<2>(t));
    cout<<(f(s1)==f(s2)?"yes":"no")<<'\n';
  }
}

