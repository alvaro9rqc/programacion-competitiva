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

struct P {
  ll h, w;
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll hr, wr, n;cin>>hr>>wr>>n;
  vector<P> data(n);
  for(auto& i: data) cin>>i.h>>i.w;
  vi ava(n,1), wrr(n), hrr(n);
  iota(all(wrr),0);
  iota(all(hrr),0);
  sort(all(hrr), [&](int j, int i){
    return tuple{data[i].h, data[i].w}<tuple{data[j].h, data[j].w};
  });
  sort(all(wrr), [&](int j, int i){
    return tuple{data[i].w, data[i].h}<tuple{data[j].w, data[j].h};
  });
  ll x=1, y=1;
  vector<ii> ans(n,{-1,-1});
  for (auto i = 0,j=0; i < n or j < n;) {
    if (i<n) {
      int e = wrr[i];
      if (ava[e]) {
        if (data[e].w==wr) { //match
          hr-=data[e].h;
          ans[e]={x,y};
          ava[e]=0;
          x+=data[e].h;
          ++i;
        }
      } else ++i; //no ava
    }
    if (j<n) {
      int e = hrr[j];
      if (ava[e]) {
        if (data[e].h==hr) { //match
          wr-=data[e].w;
          ans[e]={x,y};
          ava[e]=0;
          y+=data[e].w;
          ++j;
        } 
      } else ++j; // n o ava
    }
  }
  for(auto& [a,b]: ans) cout<<a <<' '<<b<<'\n';
}

