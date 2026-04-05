#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = tuple<int, int,int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n;cin>>n;
    vector<iii> wrr,hrr;
    for (auto i = 0; i < n; i++) {
      int x,y;cin>>y>>x;
      wrr.emplace_back(x,y);
      hrr.emplace_back(y,x);
    }
    sort(wrr.rbegin(), w.rend());
    sort(hrr.rbegin(), h.rend());
    auto f=[&](vector<iii>& a, vector<iii>& b, set<int>& s) {
      int ai=0;
      int bi=0;
      auto ad,bd,xd=a[ai++];
      int x=0,y=0;
      s.erase(xd);
      while(ai<n and get<0>(a[ai])==ad) s.erase(x+=get<2>(a[ai++]));
      if(ai==n) return {};
      while(! s.count(get<2>b[bi]))++bi;
      bi=get<1>(b[bi]);
      s.erase(get<2>b[bi++]);

    };
    vector<ii>ans;
    set<int>omp;
    for (auto i = 0; i < n; i++) omp.emplace(i);
    bool can = 1;

  }
}

