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

pair<ll,ll> f_u(ll n, int l, ll r, ll c) {
  if (l == 1) {
    if(n==1) return {r,c};
    if(n==2) return {r+1,c+1};
    if(n==3) return {r+1,c};
    return {r, c+1};
  }else{
    ll qa = (1ll << (2*l-2));
    ll ca = qa;
    ll d = (1ll << (l-1));
    if(n <= qa) return f_u(n,l-1, r,c);
    qa+=ca;
    if(n <= qa) return f_u(n-ca,l-1, r+d,c+d);
    qa+=ca;
    if(n <= qa) return f_u(n-2*ca,l-1, r+d,c);
    return f_u(n-3*ca,l-1, r,c+d);
  }
}

ll f_p(ll n, int l, ll r, ll c){
  if (l == 1){
    if (r == 1){
      if (c == 1) return n;
      else return n+3;
    } else {
      if (c == 1) return n+2;
      else return n+1;
    }
  }
  ll qa = (1ll << (2*l-2));
  ll m = (1ll << (l-1));
  if (r <= m) {
    if (c <= m) return f_p(n, l-1,r,c);
    else return f_p(n+3*qa, l-1, r, c-m);
  } else {
    if (c <= m) return f_p(n+2*qa, l-1, r-m, c);
    else return f_p(n+qa, l-1, r-m,c-m);
  }
}


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t; 
  while(t--){
    int n, q;
    cin >> n >> q;
    string id;
    for (auto i = 0; i < q; ++i) {
      cin >>  id;
      if (id == "->"){ 
        ll r, c;
        cin >> r >> c;
        cout << f_p(1, n, r, c) << '\n';
      } else {
        ll d; cin >> d;
        auto tup = f_u(d, n, 1, 1);
        auto [a, b] = tup;
        cout <<a << ' ' << b <<' ' <<'\n';
      }
    }
  }
}


