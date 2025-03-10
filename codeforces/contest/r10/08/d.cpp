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
  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    vector<pair<char,ll>> right(n);
    vector<pair<char,ll>> left(n);
    for (auto i = 0; i < n; ++i) {
      char t; int x;
      cin >> t >> x;
      left[i] = {t,x};
      cin >> t >> x;
      right[i] = {t, x};
    }
    vector<bool> direc(n, false);
    auto toright= [&right, &left] (int idx) {
      auto[tl, nl] = left[idx];
      auto[tr, nr] = right[idx];
      if(tl == tr) {
        if (tr == '+' or nr == nl) return 0;
        else return (nr > nl)? 1:-1;
      }
      if(tl == 'x') return -1;
      else return 1;
    };
    direc.back() = toright(n-1)==1;
    for (auto i = n-2; i >= 0; --i) {
      int r = toright(i);
      if (r == 1) direc[i]=true;
      else if (r == -1) direc[i]=false;
      else direc[i]=direc[i+1];
    }
    ll r=1,l=1, inc=0;
    for (int i = 0; i < n; ++i) {
      auto [tl, nl]=left[i];
      ll il = (tl=='+')? nl:(l*(nl-1));
      auto [tr, nr] = right[i];
      ll ir = (tr == '+')? nr:(r * (nr-1));
      inc = il+ir;
      if(direc[i]) r+=inc;
      else l+=inc;
    }
    cout << r +l<<'\n';
  }

}


