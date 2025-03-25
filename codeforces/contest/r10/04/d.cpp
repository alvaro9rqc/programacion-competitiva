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
  int t;
  cin  >> t;

  while(t--) {
    int n; 
    cin >> n;
    vector x(n);
    int idx_low=0, idx_up=0, idx_pup=0;
    for(auto& e: x) cin >> e;
    for (auto i = 0; i < n; ++i) {
      if( x[i] < x[idx_low] ) idx_low=i;
      if( x[i] >= x[idx_up] ) idx_pup=idx_up, idx_up=i;
      if( x[i] > x[idx_pup] ) idx_pup=i;
    }
    cout << "? "<<idx_low<<' '<<idx_pup<<'\n'<<flush;
    int ans1; cin >> ans1;
    cout << "? "<<idx_low<<' '<<idx_up<<'\n'<<flush;
    int ans2; cin >> ans1;
    int d1 = int(abs(x[idx_low]-x[idx_up]));
    int d2 = int(abs(x[idx_low]-x[idx_pup]));
    if (ans1 == 0 or ans1 < d1 or ans2 == 0 or ans2 <d2){
      cout << "! A\n"<<flush;
      continue;
    }
    if (ans1 >= n or ans2 >= n) {
      cout << "! B\n"<< flush;
      continue;
    }

  }
}


