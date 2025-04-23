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
  ll t; cin >> t; 
  while(t--){
    ll n; cin >> n;
    vll a(n), b(n), pos(n+10);
    for (ll i = 0; i < n; ++i) {
      cin >> a[i];
      pos[a[i]]=i;
    }
    for(auto& e: b) {
      cin >> e;
    }
    bool puede = true;
    ll c_i=0;
    ll rep;
    for (auto i = 0; i < n; ++i) {
      if (a[i]==b[i]){
        c_i ++;
        rep=a[i];
        if ( (c_i > 0 and n%2==0) or (c_i > 1 and n%2==1) ) {
          puede=false;
          break;
        }
      } else {
        if (a[i] != b[ pos[b[i]] ]) {
          puede=false; 
          break;
        }
      }
    }
    auto cp = [&a,&b,&pos](ll i, ll j){
      swap(a[i],a[j]);
      swap(b[i],b[j]);
      pos[a[i]]=i;
      pos[a[j]]=j;
    };
    if (puede ){
      vector<tuple<ll,ll>> ans;
      if (n&1 and pos[rep] != n/2 ){
        ans.emplace_back(pos[rep]+1, n/2+1);
        cp(pos[rep], n/2);
      }
      for (ll i = 0; i < n/2+1; ++i) {
        ll pd = n-i-1;
        if ( pd != pos[ b[i] ] ){
          ans.emplace_back(pd+1, pos[b[i]]+1);
          //cerr <<":: "<< pd+1 << ' '<<pos[b[i]]+1 << '\n';
          cp(pd, pos[b[i]]);
        }
      }
      cout << ans.size()<<'\n';
      for(auto& [i,j]: ans) {
        cout << i << ' '<< j<<'\n';
      }
    } else{
      cout << -1 << '\n';
    }
  }
}


