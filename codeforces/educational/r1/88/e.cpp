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

tuple<string, vi> f(ll n) {
  vi nr(10);
  string s;
  int t=0;
  while(1) {
    ll m = n;
    ll nn = 0;
    while(m) {
      ll x=m%10;
      nn+=x;
      ++nr[x];
      m/=10;
      s.push_back(char(x+'0'));
    }
    reverse(s.begin()+t,s.end());
    t=sz(s);
    if(n<10) break;
    n=nn;
  }
  return {s,nr};
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    string s;cin>>s;
    if(sz(s)<2) {
      cout<<s<<'\n';
      continue;
    }
    vi nr(10);
    ll st=0;
    for(auto& i: s) ++nr[i-'0'];
    for (auto i = 0; i < 10; i++) st+=nr[i]*i;
    string ans = "";

    // auto[suf, nu] = f(9);
    // cout<<suf<<'\n';
    for (auto i = 1ll; i < st+1; i++) {
      auto[suf, nu] = f(i);
      ll s0 = 0;
      for (auto j = 0; j < 10; j++) {
        if(nu[j]>nr[j]){s0=-1;break;}
        s0+=(nr[j]-nu[j])*j;
      }
      if(s0==i) {
        for (auto j = 9; j >= 0; j--) ans.append(nr[j]-nu[j],char(j+'0'));
        ans+=suf;
        break;
      }
    }
    cout<<ans<<'\n';
  }
}

