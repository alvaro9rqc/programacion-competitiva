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
  ll N,M; cin >> N >> M;
  set<ll> L, R;
  for (ll i = 0; i < N; ++i) {
    ll l, r; cin >> l >> r;
    L.insert(l);
    R.insert(r);
  }
  auto y = R.begin();
  auto x = L.upper_bound(*y);
  --x;
  ll ans = 0;
  ll p = 1;
  while(p <= *x) {
    //cout << "-> " << p <<' ' <<*x <<' '<< *y<<'\n';
    ll d1 = *y - p;
    ll d2 = *y - *x-1;
    ans += d1*(d1+1) / 2 - d2*(d2+1) / 2;
    //cout <<": " << ans <<'\n';
    p = *x + 1;
    y++;
    x = --L.upper_bound(*y);
  }
  ans += (M-p+1)*(M-p+2) / 2;
  cout << ans <<'\n';
  return 0;
}


