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

using vpl = vector<pair<ll,ll>>;
using pl = pair<ll,ll>;

vpl c1,c2,c3,c4;

bool f1(pl a, pl b) {
  auto[xa,ya]=a;
  auto[xb,yb]=b;
  return ya*xb>yb*xa;
}
bool f2(pl a, pl b) {
  auto[xa,ya]=a;
  auto[xb,yb]=b;
  return ya*xb*-1<yb*xa*-1;
}

int fl(pl pt) {
  auto [x,y] = pt;
  if (x>0) {
    if(y>0) {
      auto it = lower_bound(all(c1), pt, f1);
      return sz(c4)+sz(c3)+sz(c2) + int(it-c1.begin()+1);
    }
    else {
      auto it = lower_bound(all(c4), pt, f2);
      return int(it-c4.begin()+1);
    }
  } else {
    if(y>0) {
      auto it = lower_bound(all(c2), pt, f2);
      return sz(c3)+sz(c4)+int(it-c2.begin()+1);
    }
    else {
      auto it = lower_bound(all(c3), pt, f1);
      return sz(c4)+int(it-c3.begin()+1);
    }
  }
}

int fu(pl pt) {
  auto [x,y] = pt;
  if (x>0) {
    if(y>0) {
      auto it = upper_bound(all(c1), pt, f1);
      return sz(c4)+sz(c3)+sz(c2) + int(it-c1.begin());
    }
    else {
      auto it = upper_bound(all(c4), pt, f2);
      return int(it-c4.begin());
    }
  } else {
    if(y>0) {
      auto it = upper_bound(all(c2), pt, f2);
      return sz(c3)+sz(c4)+int(it-c2.begin());
    }
    else {
      auto it = upper_bound(all(c3), pt, f1);
      return sz(c4)+int(it-c3.begin());
    }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q; cin >> n >> q;
  vpl pts(n);
  for(auto& [x,y]: pts) {
    cin >> x >> y;
    if (x>0) {
      if(y>0) c1.emplace_back(x,y);
      else c4.emplace_back(x,y);
    } else {
      if(y>0) c2.emplace_back(x,y);
      else c3.emplace_back(x,y);
    }
  }
  sort(all(c1), f1);
  sort(all(c2), f2);
  sort(all(c3), f1);
  sort(all(c4), f2);

  for (auto i = 0; i < q; i++) {
    int a, b; cin >> a >> b;
    --a,--b;
    a = fl(pts[a]);
    b = fu(pts[b]);
    int ans = 0;
    if (b > a ) ans=b-a+1;
    else if (b < a) ans = n - (a - b -1);
    cout << ans <<'\n';
  }
}

