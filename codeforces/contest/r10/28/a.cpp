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
  int tt; cin >> tt;
  while(tt--) {
    ll a, b, c, d; cin >> a>>b>>c>>d;
    ll g  = min(a,c);
    ll f  = min(b,d);
    //cerr << a << '\n';
    if (g < f) cout << "Flower\n";
    else cout << "Gellyfish\n";
  }
}


