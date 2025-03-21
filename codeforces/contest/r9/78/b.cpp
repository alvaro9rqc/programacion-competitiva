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
  int t; cin >> t;
  while(t--) {
    int x,n;
    cin >> n >> x;
    priority_queue<int> pq;
    for (auto i = 0; i < n; ++i) {
      int a; cin>>a;
      pq.push(a);
    }
    ll ans = 0;
    while( not pq.empty() ) {
      int lim = min(int( pq.size() ), x);
      stack<int> st;
      int lan = pq.top();
      for (auto i = 0; i < lim; ++i) {
        st.push(pq.top());
        pq.pop();
      }
      ans += lan;
      //for (auto i = 0; i < lim; ++i) {
      //  if (st.top()-lan > 0) pq.push(st.top()-lan);
      //  st.pop();
      //}
    }
    cout << ans <<'\n';
  }
}


