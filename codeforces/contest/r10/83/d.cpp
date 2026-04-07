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

struct FT_s {
  vector<int> s;
  FT_s(int n) : s(n) {}
  void update(int pos, int dif) { // a [pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos] = max(dif,s[pos]);
  }
  int query(int pos) { // sum of values in [0 , pos)
    int res = 0;
    for (; pos > 0; pos &= pos - 1) 
      res=max(res,s[pos-1]);
    return res;
  }
};

struct FT_p {
  vector<int> s;
  FT_p(int n) : s(n) {}
  void update(int pos, int dif) { // a [pos] += dif
    pos=sz(s)-pos-1;
    for (; pos < sz(s); pos |= pos + 1) s[pos] = max(dif,s[pos]);
  }
  int query(int pos) { // sum of values in [0 , pos)
    pos=sz(s)-pos;
    int res = 0;
    for (; pos > 0; pos &= pos - 1) 
      res=max(res,s[pos-1]);
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n;cin>>n;
    vi val(n); for(auto& i: val) cin >> i;
    FT_s s_inct(n+1),p_dect(n+1);
    FT_p p_inct(n+1),s_dect(n+1);
    vi s_inc(n+1);
    vi p_inc(n+1);
    vi s_dec(n+1);
    vi p_dec(n+1);
    int ans = n;
    for(auto& i: val) {
      s_inc[i]=1+s_inct.query(i);
      s_inct.update(i,s_inc[i]);
      s_dec[i]=1+s_dect.query(i);
      s_dect.update(i,s_dec[i]);
    }
    for (auto j = n-1; j >= 0; j--) {
      auto i = val[j];
      p_inc[i]=1+p_inct.query(i);
      p_inct.update(i,p_inc[i]);
      p_dec[i]=1+p_dect.query(i);
      p_dect.update(i,p_dec[i]);
    }
    for (auto i = 0; i < n; i++) {
      dbg(i);
      dbg(s_inc[val[i]]);
      dbg(s_dec[val[i]]);
      dbg(p_inc[val[i]]);
      dbg(p_dec[val[i]]);
    }
    raya;
    for (auto i = 0; i < n; i++) {
      int lans = n;
      auto x = val[i];
      lans=min(lans, n - (s_inc[x] + p_inc[x]-1));
      lans=min(lans, n - (s_dec[x] + p_dec[x]-1));
      lans=min(lans, n - (s_dec[x] + p_inc[x]-1));
      ans=min(lans,lans);
    }
    cout<<ans<<'\n';
  }
}

