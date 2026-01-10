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
#define double long double

struct R {
  double sx,sy,ex,ey;
  double cos, sen, mod, lx, ly;

  R(vi arr) {
    sx=arr[0];
    sy=arr[1];
    ex=arr[2];
    ey=arr[3];
    ly = ey-sy;
    lx = ex-sx;
    mod = hypot(sx-ex, sy-ey);
    cos = lx/mod;
    sen = ly/mod;
  }
};

double squ(double a) {return a*a;}

double eps = 1e-9;

struct F {
  double a,c,b;
  F(double a1, double b1, double c1) {
    a=a1,b=b1,c=c1;
  }
  double f(double x) {
    auto r = a*x*x+b*x+c;
    if (r<0) r = 0;
    return r;
  }
};

double parab(R a, R b) {
  double nx = a.cos-b.cos,
  mx = a.sx - b.sx,
  my = a.sy - b.sy,
  ny = a.sen - b.sen;
  double A = nx*nx + ny*ny,
  B = (mx*nx + my*ny)*2,
  C = mx*mx+my*my;
  F f(A,B,C);
  double e = a.mod;
  //dbg(A);
  //dbg(a.cos);
  //dbg(-b.cos);
  if (abs(A)<eps) {
    return min(
      sqrt(f.f(0)),
      sqrt(f.f(e))
    );
  } else {
    double x = -B/(2*A);
    if (x < 0) x = 0;
    else if (x > e) x = e;
    return sqrt(f.f(x));
  }
}

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x=0, T y=0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
  bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
  P operator+(P p) const { return P(x+p.x, y+p.y); }
  P operator-(P p) const { return P(x-p.x, y-p.y); }
  P operator*(T d) const { return P(x*d, y*d); }
  P operator/(T d) const { return P(x/d, y/d); }
  T dot(P p) const { return x*p.x + y*p.y; }
  T cross(P p) const { return x*p.y - y*p.x; }
  T cross(P a, P b) const { return (a-*this).cross(b-*this); }
  T dist2() const { return x*x + y*y; }
  double dist() const { return sqrt((double)dist2()); }
  // angle to x-axis in interval [-pi, pi]
  double angle() const { return atan2(y, x); }
  P unit() const { return *this/dist(); } // makes dist()=1
  P perp() const { return P(-y, x); } // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated 'a' radians ccw around the origin
  P rotate(double a) const {
    return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")"; }
};


typedef Point<double> P;
//Returns the shortest distance between point p and the line segment from point s to e.
//double segDist(P& s, P& e, P& p) {
//  if ((e-s).dist2() < eps) return (p-s).dist();
//  auto d = (e-s).dist2(), t = clamp((p-s).dot(e-s),.0,d);
//  return ((p-s)*d-(e-s)*t).dist()/d;
//}
double segDist(P s, P e, P p) {
    double l2 = (e - s).dist2(); // Longitud del segmento al cuadrado
    if (l2 < eps) return (p - s).dist(); // El segmento es un punto
    
    // t es la proyección normalizada (0 a 1)
    double t = ((p - s).dot(e - s)) / l2;
    
    // Clampeamos t al segmento [0, 1]
    t = max(0.0L, min(1.0L, t));
    
    // Encontramos el punto de proyección exacto
    P projection = s + (e - s) * t;
    
    // Devolvemos la distancia simple
    return (p - projection).dist();
}


double fin(R a, R b) {
  P b1(b.sx+b.cos*a.mod, b.sy+b.sen*a.mod), b2(b.ex,b.ey), a1(a.ex, a.ey);
  return segDist(b1,b2,a1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin >> tt;
  while(tt--) {
    vi arr(4);
    for(auto& i: arr) cin>> i;
    R a(arr);
    for(auto& i: arr) cin>> i;
    R b(arr);
    if (a.mod > b.mod) swap(a,b);
    double ans = min(parab(a, b), fin(a,b));
    //double ans = parab(a, b);
    printf("%.10Lf\n", ans);
  }
}

