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

const ll LIM =(ll) 10000010;

bitset<LIM>bs;
vll p;

void sieve() {
  bs.set();
  bs[0]=0;
  bs[1]=1;
  for (ll i = 2; i < LIM; ++i) {
    if(bs[i]){
      for (ll j = i*i; j < LIM; j+=i) {
        bs[j]=0;
      }
      p.push_back(i);
    }
  }
}

ll npf(ll n) {
  ll ans = 0;
  for (auto i = 0ull; i < p.size() && (p[i]*p[i] <= n); ++i) {
    if (n%p[i]==0)++ans;
    while(n%p[i]==0){
      n/=p[i]; 
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  vll ans(LIM);
  for (ll i = 1; i < LIM; ++i) {
    ans[i]=ans[i-1]+npf(i);
  }
  int t;cin >> t;
  while(t--) {
    int x; cin >> x;
    cout << ans[x]<<'\n';
  }
}


