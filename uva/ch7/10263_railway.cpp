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



template<class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x_=0, T y_=0): x(x_), y(y_){}
// dist, -, dist2, dot, *, /
  bool operator==(P p) const {return tie(x,y)==tie(p.x,p.y);}
  P operator -(P p) const {return P(x-p.x, y-p.y);}
  P operator +(P p) const {return P(x+p.x, y+p.y);}
  P operator *(T d) const { return P(x*d, y*d); }
  P operator /(T d) const { return P(x/d, y/d); }
  T dot(P p) const {return x*p.x+y*p.y;}
  T dist2() const {return x*x + y*y;}
  double dist() const {return sqrt(double(dist2()));}
};

using P = Point<double>;
P nearP(P&s, P&e, P& p) {
  if (s == e) return s;
  P a = p - s;
  P b = e - s;
  auto mb2 = b.dist2();
  auto c = a.dot(b);
    //dbg(c);
    //dbg(mb2);
  if (c < 0) {
    return s;
  } else if (c > mb2) return e;
  else return s+b*c/mb2;

}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  //cin.exceptions(cin.failbit);
  P ori; 
  while(1) {
    cin >> ori.x >> ori.y;
    if (cin.eof()) break;
    int n; cin >> n;
    //dbg(ori.x);
    //dbg(ori.y);
    //dbg(n);
    P bef, cur; 
    cin >> bef.x >> bef.y;
    double dis = 1e15;
    P p = bef;
    for (auto i = 0; i < n; i++) {
      cin >> cur.x >> cur.y;
      auto x = nearP(bef, cur, ori);
      //dbg(x.x);
      //dbg(x.y);
      //cout << "gaaaa\narP";
      if ((x-ori).dist2() < dis) {
        p = x;
        dis = (x-ori).dist2();
      }
      swap(cur, bef);
    }
    //dbg(dis);
    //dbg(p.x);
    //dbg(p.y);
    cout << format("{:.4f}\n{:.4f}\n", p.x,p.y);
    //raya;
  }
}

