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
  ll T; cin >> T;
  while(T--) {
    ll nP, nC;
    cin >> nP >> nC;
    vll P(nP);
    vll C(nC);
    vll N={0};
    for(auto& i: P) {
      cin >> i;
      N.push_back(i);
    }
    for(auto& i: C) {
      cin >> i;
      N.push_back(i);
    }
    sort(P.begin(), P.end());
    sort(C.begin(), C.end());
    sort(N.begin(), N.end());
    ll bid=0, ang=nP+nC;
    for (ll i = 0; i < (ll)N.size(); ++i) {
      ll hap = (ll)(upper_bound(P.begin(), P.end(),N[i])-P.begin())+
        (ll)(C.end()-lower_bound(C.begin(),C.end(),N[i]));
      ll loc = nP+nC-hap;
      if(loc < ang ) {
        bid=N[i];
        ang=loc;
      } 
    }
    cout << bid <<' '<<ang<<'\n';
  }
}


