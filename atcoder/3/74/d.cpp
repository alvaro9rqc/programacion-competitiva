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
  int N, Tl, Ts; cin >> N >> Ts >> Tl;
  deque<vll> dq(N, vll(4));
  for(auto& ps: dq) {
    cin
      >> ps[0]
      >> ps[1]
      >> ps[2]
      >> ps[3];
  }
  //cout << "l: " << dq.size()<<'\n';
  int x=0,y=0;
  double T = 0;
  auto fd2=[](ll x, ll y, ll a, ll b) {
    return (x-a)*(x-a) + (y-b)*(y-b);
  };
  while (! dq.empty()) {
    auto p = dq.begin();
    ll d2 = fd2(x,y,( *p )[0],(*p)[1]);
    ll nx=(*p)[2], ny=(*p)[3];
    for(auto it = dq.begin(); it != dq.end(); ++it) {
      auto& pp = *it;
      ll t = fd2(x,y,pp[0],pp[1]);
      if (t < d2) {
        d2 = t;
        p = it;
        nx = pp[2];
        ny = pp[3];
      }
      t = fd2(x,y,pp[2],pp[3]);
      if (t < d2) {
        d2 = t;
        p = it;
        nx = pp[0];
        ny = pp[1];
      }
    }
    x = nx; y=ny;
    //cout << x <<' '<<y<<'\n';
    T += sqrt(d2)/ Ts + sqrt(fd2((*p)[0],(*p)[1],(*p)[2],(*p)[3])) / Tl;
    dq.erase(p);
    //cout <<"-> "<< d2 << '\n';
    //cout << T <<'\n';
  }
  cout << T << '\n';
  return 0;
}


