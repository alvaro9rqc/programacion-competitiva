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
  string s;cin>>s;
  for(auto& i: s) i-='a';
  int alf = 26;
  int n = sz(s);
  vector<vi> pre(alf, vi(n+1));
  for (auto i = 1; i < n+1; i++) {
    for (auto c = 0; c < alf; c++) {
      pre[c][i]=pre[c][i-1]+(s[i-1]==c);
    }
  }
  auto f= [&](int c, int l, int r){return pre[c][r]-pre[c][l];};
  auto f2=[&](int c, int l, int r){
    return f(c,0,l) or f(c,r+1,n);
  };
  int ans = 0;
  for (auto i = 0; i < n; i++) {
    set<int>ost;
    vi ele;
    int dif=0;
    int l=i,r=i;
    while(1) {
      if(dif==0) ans=max(ans,r-l+1);
      else if (dif==1) {
        if(f2(ele[0],l,r) or f2(ele[1],l,r) or s[i]==ele[0] or s[i]==ele[1])
          ans=max(ans,r-l+1);
      } else {
        if(sz(ost)>2 or dif>2) break;
        ans=max(ans,r-l+1);
      }
      if(l==0 or r==n-1) break;
      --l,++r;
      if(s[l]!=s[r]) {
        ost.emplace(s[l]);
        ost.emplace(s[r]);
        ele.emplace_back(s[l]);
        ele.emplace_back(s[r]);
        ++dif;
      }
    }
  }
  for (auto i = 0,j=1; j < n; i++,++j) {
    set<int>ost;
    vi ele;
    int dif=0;
    int l=i,r=j;
    if(s[i]!=s[j]) {
      ost.emplace(s[i]);
      ost.emplace(s[j]);
      ele.emplace_back(s[l]);
      ele.emplace_back(s[r]);
      dif++;
    }
    while(1) {
      if(dif==0) ans=max(ans,r-l+1);
      else if (dif==1) {
        if(f2(ele[0],l,r) or f2(ele[1],l,r))
          ans=max(ans,r-l+1);
      } else {
        if(sz(ost)>2 or dif>2) break;
        ans=max(ans,r-l+1);
      }
      if(l==0 or r==n-1) break;
      --l,++r;
      if(s[l]!=s[r]) {
        ost.emplace(s[l]);
        ost.emplace(s[r]);
        ele.emplace_back(s[l]);
        ele.emplace_back(s[r]);
        ++dif;
      }
    }
  }
  cout<<ans<<'\n';
}

