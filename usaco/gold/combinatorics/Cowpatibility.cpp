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
  ll lim = ll(1e6+10);
  ifstream cin("cowpatibility.in");
  vl s1(lim);
  map<pair<ll,ll>,ll> s2;
  using lll = tuple<ll,ll,ll>; 
  using llll = tuple<ll,ll,ll,ll>;
  using lllll = tuple<ll,ll,ll,ll,ll>;
  map<lll,ll> s3;
  map<llll,ll> s4;
  map<lllll,ll> s5;
  ll n; cin >> n;
  ll nn = n;
  vl ele(5);
  ll ans = 0;
  while(nn--) {
    for(auto& i: ele) cin >> i;
    sort(all(ele));
    //1
    for(auto& i: ele) ans+= s1[i]++;
    //2
    for (auto i = 0; i < 4; i++) 
      for (auto j = i+1; j < 5; j++) 
        ans-=s2[{ele[i],ele[j]}]++;
    //3
    for (auto i = 0; i < 3; i++) 
      for (auto j = i+1; j < 4; j++) 
        for (auto k = j+1; k < 5; k++) 
          ans+=s3[{ele[i],ele[j], ele[k]}]++;
    //4
    for (auto x = 0; x < 2; x++) 
      for (auto i = x+1; i < 3; i++) 
        for (auto j = i+1; j < 4; j++) 
          for (auto k = j+1; k < 5; k++) 
            ans-=s4[{ele[x],ele[i],ele[j], ele[k]}]++;
    //5
    ans+=s5[{ele[0],ele[1],ele[2],ele[3], ele[4]}]++;
  }
  ofstream cout("cowpatibility.out");
  cout << (n*(n-1)/2-ans)<<'\n';
}

