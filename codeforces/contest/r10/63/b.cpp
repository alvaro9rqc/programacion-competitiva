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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n;cin>>n;
    vi val(n); for(auto& i: val) cin >> i;
    string s;cin>>s;
    int bi,ei;
    bi=ei=0;
    for (auto i = 0; i < n; i++) {
      if(val[i]==1)bi=i;
      else if (val[i]==n)ei=i;
    }
    if(s[bi]=='1' or s[ei]=='1' or s.front()=='1' or s.back()=='1') {
      cout<<"-1\n";continue;
    }
    ++bi,++ei;
    cout<<format("5\n"
                 "{} {}\n"
                 "{} {}\n"
                 "{} {}\n"
                 "{} {}\n"
                 "{} {}\n",
                 1, bi,
                 min(bi,ei), max(ei,bi),
                 bi, n,
                 1, ei,
                 ei, n
                 );

  }
}

