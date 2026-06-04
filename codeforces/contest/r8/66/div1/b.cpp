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

using viii = vector<tuple<ll,ll,ll>>;

tuple<ll,ll,bool> fi(viii a, viii b, ll n) {
  ll d1f=0,d2f=0;
  vector<bool> vis(n);
  ll tk =0;
  d1f=get<0>(a.back());
  while(sz(a) and get<0>(a.back())==d1f) {
    auto [d1,d2,id]=a.back();
    a.pop_back();
    vis[id]=1;
    d2f+=d2;
    ++tk;
  }
  if(tk==n) return {d1f,d2f,1};
  while(vis[get<2>(b.back())]) b.pop_back();
  d2f+=get<0>(b.back());
  ll d1o=d1f,d2o=get<0>(b.back());
  bool tb = 1;
  // dbg(d1o);
  // dbg(d2o);
  bool xd = 0;
  while(tk!=n) {
  // while(0) {
    // dbg(n);
    auto& c = (tb)?b:a;
    auto& dob = (tb)?d2o:d1o;
    auto& dal = (tb)?d1o:d2o;
    while(vis[get<2>(c.back())]) c.pop_back();
    if(!sz(c)) break;
    auto [d1,d2,id]=c.back();
    // dbg(d1);
    // dbg(d2);
    // dbg(id);
    // dbg(tb);
    // dbg("---");
    // dbg(id);
    if(d1 == dob) {//lo tomo
      dal-=d2;
      vis[id]=1;
      xd=0;
      ++tk;
    } else if(d1>dob or xd) return {0,0,0};
    else {tb^=1;xd=1;}
  }
  //post condicion: alguna tiene que ser 0
  return {d1f,d2f, (tk==n and (d1o==0 or d2o==0))};
}


void solve() {
  ll n;cin>>n;
  viii hrr,wrr;
  for (auto i = 0; i < n; i++) {
    ll h,w;cin>>h>>w;
    hrr.emplace_back(h,w,i);
    wrr.emplace_back(w,h,i);
  }
  sort(all(hrr));
  sort(all(wrr));
  auto [h1,w1, c1]=fi(hrr,wrr,n);
  auto [w2,h2, c2]=fi(wrr,hrr,n);
  if(c1 and c2) {
    if(h1==h2 and w1==w2) {
      cout<<"1\n";
      cout <<h1<<' '<<w1<<'\n';
    } else {
      cout<<"2\n";
      cout <<h1<<' '<<w1<<'\n';
      cout <<h2<<' '<<w2<<'\n';
    }
  } else if (c1) {
    cout<<"1\n";
    cout <<h1<<' '<<w1<<'\n';
  } else if(c2) {
    cout<<"1\n";
    cout <<h2<<' '<<w2<<'\n';
  }
  // raya;
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

