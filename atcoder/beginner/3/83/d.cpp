#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<ll> sq;
vector<ll> p;

const ll LIM = 2000010ll;

bitset<LIM> bs;

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i < LIM; ++i) {
    if (bs[i]) {
      for (ll j = i*i; j < LIM; j+=i) {
        bs[j] = 0;
      }
      p.push_back(i);
      sq.push_back(i*i);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  ll n; cin >> n;
  ll i=0;
  ll ans = 0;
  bool f=true;
  while (true) {
    ll pot = 1;
    for (auto j = 0; j < 8; ++j) {
      pot*=p[i];
      if (pot > n) {
        f = false;
      }
    }
    if (f and pot <= n) ++ans;
    auto it = upper_bound(sq.begin(),sq.end(),n/sq[i]);
    //cout << "-> " <<n/sq[i]<<'\n';
    --it;
    ll d = distance(sq.begin()+i, it);
    if (d<=0) break;
    ans += d;
    //cout << p[i] << ' ' << *it <<' '<<d<< ' '<<ans<<'\n';
    ++i;
  }
  cout << ans << '\n';
  return 0;
}


