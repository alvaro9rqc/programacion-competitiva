#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    ll c, b, d;
    cin >> b >> c >> d;
    ll sum = 0;
    ll a=0;
    bool isp=true;
    auto req = [&sum, &d](int i) {
      ll bs = sum & (1ll<<i);
      ll bd = d & (1ll<<i);
      int r = (bs == bd)?0:1;
      if (r==1 and bs != 0) {
        if(i==60) return -1;
        sum += 1ll << (i+1);
      }
      return r;
    };
    auto pass = [&](int r, int i) {
      ll bb = b&(1ll<<i);
      ll bc = c&(1ll<<i);
      if (r) {
        if (bb == 0 and bc != 0) return false;
        if (bb == 0 and bc == 0) a|=1ll<<i;
        return true;
      } else {
        if (bb != 0 and bc == 0) return false;
        //a |= 1ll << i;
        if (bb & bc) 
        {
          if(i==60) return false;
          sum += 1ll << (i+1);
          a|=1ll<<i;
        }
        return true;
      }
    };
    for (auto i = 0; i < 61; ++i) {
      int r = req(i);
      if (r==-1 or not pass(r, i) ){
        isp=false;
        break;
      }
    }
    if(isp) cout << a<<'\n';
    else cout << -1<< '\n';
  }
}


