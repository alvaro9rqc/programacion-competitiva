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
    ll n; cin >> n;
    vll A(2*n);
    for(auto& e: A) cin >> e;
    sort(A.rbegin(), A.rend());
    //for(auto& e: A) cout << e <<' ';
    //cout << '\n';

    ll suml = accumulate(A.begin(), A.begin()+n+1,0);
    ll sumr = accumulate(A.begin()+n+1, A.end(),0);
    //cout << "::" <<suml <<' '<< sumr <<'\n';
    A.push_back(suml - sumr);
    cout << A[n] << ' ';
    for (ll i = 0; i < n; ++i) {
      cout << A[n+1+i] <<' ' << A[i]<<' ';
    }
    cout <<'\n';
  }
}


