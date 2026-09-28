#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

ll ssp=8;
set<int> prr= {
  0b0000,
  0b0011,
  0b0101,
  0b1001,
  0b0110,
  0b1010,
  0b1100,
  0b1111
};

ll fx(int x) {
  return x%3==0;
}

void solve() {
  int n,qry;cin>>n>>qry;
  vi arr(n); 
  for(auto& i: arr) cin >> i;
  int c3 = 0;
  if(n==1) {
    cout<<fx(arr[0])<<' ';
    for (auto i = 0; i < qry; i++) {
      int xd;cin>>xd;
      cin>>arr[0];
      cout<<fx(arr[0])<<' ';
    }
  } else {
    for(auto& i: arr) c3+=prr.count(i);
    cout<<c3<<' ';
    for (auto i = 0; i < qry; i++) {
      int idx,x;cin>>idx>>x;
      --idx;
      c3-=prr.count(arr[idx]);
      c3+=prr.count(arr[idx]=x);
      cout<<c3<<' ';
    }
  }
  cout<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

