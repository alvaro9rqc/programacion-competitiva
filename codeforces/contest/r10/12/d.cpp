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

const ll LIM = 100010;

bitset<LIM> bs;
set<ll> p;

void sieve() {
  bs.set();
  bs[0]=0;
  bs[1]=0;
  for (auto i = 2ll; i < LIM; ++i) {
    if(bs[i]) {
      for (auto j = i*i; j < LIM; j+=i) bs[j]=0;
      p.insert(i);
    }

  }
}


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  ll t;
  cin >> t;
  while(t--) {
    ll n; cin >> n;
    set<ll> disp;
    for (auto i = 1; i <= n; ++i) {
      disp.insert(i);
    }
    auto primo = (--p.upper_bound(n));
    ll ac_s = 0;
    ll np=0,lim=n/3-1;

    for (auto i = 1ll; i <= n; ++i) {
      ll s_lo = (*primo-1)*i;
      ll s_up = (*primo)*i;
      auto it = disp.upper_bound(s_lo - ac_s);
      if (it == disp.end()) {
        --primo;
        s_lo = (*primo-1)*i;
        s_up = (*primo)*i;
        it = disp.upper_bound(s_lo - ac_s);
      }
      ac_s += *it;
      if (s_lo < ac_s and ac_s <= s_up) ++np;
      cout << *it << ' ';
      disp.erase(it);
      if (np >= lim) {
        i=n;
        for(auto& e: disp) cout << e <<' ';
      }
    }
    cout << '\n';
  }
}


