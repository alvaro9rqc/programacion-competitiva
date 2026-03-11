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

ll n,m,mitad;
vl v;

vector<unordered_map<ll,ll>> m_n,m_1;


ll dp_n(ll i, ll s) {
  if(i>=n) return s==0;
  if(m_n[i].count(s))return m_n[i][s];
  //lo tomo o no
  return m_n[i][s]=dp_n(i+2, (s+v[i])%m) + dp_n(i+1,s);
}

ll dp_1(ll i, ll s) {
  if(i>mitad) {
    auto it = m_1[i].find((m-s)%m);
    return (it != m_1[i].end())?it->second:0;
  }
  // if(m_1[i].count(s))return m_1[i][s];
  auto it = m_1[i].find(s);
  if(it != m_1[i].end()) return it->second;
  //lo tomo o no
  return m_1[i][s]=dp_1(i+2, (s+v[i])%m) + dp_1(i+1,s);
}

void dp_2() {
  m_1[n][0]=1;
  m_1[n-1][0]=1;
  m_1[n-1][v[n-1]]+=1;
  for (auto i = n-2; i > mitad; i--) {
    for(auto& [s,r]: m_1[i+1]) m_1[i][s]=r;
    for(auto& [s,r]: m_1[i+2]) m_1[i][(s+v[i])%m]+=r;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  //m_1 len = n+1
  cin>>n>>m;
  v.resize(n);for(auto& i: v) cin>>i;
  if(n<10) {
    m_n.resize(n);
    cout<<dp_n(0,0)<<'\n';
  } else {
    m_1.resize(n+1);
    mitad=n/2;
    dp_2();
    cout<<dp_1(0,0)<<'\n';
  }
}

