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
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  using p = pair<char, ll>;
  while(t--){
    int n; cin >> n;
    vector<vector<p>> m(n, vector<p>(2));
    for (auto i = 0; i < n; ++i) {
      char o1, o2;
      int n1, n2;
      cin >> o1 >> n1 >> o2 >> n2;
      m[i][0]= {o1, n1};
      m[i][1]= {o2, n2};
    }
    vector<bool> to_left(n, true);
    auto imp = [&](vector<p> v) {
      auto[ol, nl] = v[0];
      auto[opr, nr] = v[1];
      if (ol == opr and ol == 'x') {
        return nl != nr; // x2 x3
      }
      if (ol != opr) return true; // x +
      return false;
    };
    auto lado = [&] (vector<p> v) {
      auto[ol, nl] = v[0];
      auto[opr, nr] = v[1];
      if (ol == opr) // x3 x2
        return nl == 3;
      return ol == 'x'; //x +
    };
    for (auto i = n-2; i >= 0; --i) {
      if (imp(m[i+1])) to_left[i] = lado(m[i+1]);
      else to_left[i] = to_left[i+1];
    }
    ll l=1,r=1;
    int i = 0;
    for(auto& v: m) {
      auto[ol, nl] = v[0];
      auto[opr, nr] = v[1];
      ll inc = 0;
      if (ol == '+') inc += nl;
      else inc += (l)*(nl-1);
      if (opr == '+') inc += nr;
      else inc += (r)*(nr-1);
      // incremento total = inc
      if(to_left[i++]) l += inc;
      else r += inc;
    }
    cout << l + r << '\n';
    // x +    [0]
    // + +
    // + +
    // + +
    // + +
    // x +    [n]
    //
    //
    //
    //
    // x2 x3
  }
}


