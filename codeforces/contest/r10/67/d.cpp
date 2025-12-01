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

string s, t;
vector<ii> ans;
int n; 

char sw(char x) {
  return x=='1'?'0':'1';
}

bool trs(int i) { return s[i]==s[i+1]; }

void peer(int i) {
  char c = s[i];
  int l = i, r=i;
  while(0<=l or r < n) {
    while(0<=l and s[l]==c) --l;
    while(r<n and s[r]==c) ++r;
    if (l<0 and r>=n) continue;
    ans.emplace_back(l+2, r);
    c = sw(c);
    for (auto j = l+1; j < r; j++) s[j]=sw(s[j]);
  }
}

void lf(int i) {
  char c = s[i];
  ++i;
  for (auto j = 0; j < i-1; j++) {
    if (s[j]!=t[j]) {
      ans.emplace_back(j+1, i+1);
      for (auto k = j; k < i+1; k++) s[k]=sw(s[k]);
    }
  }
  if (c!=s[i]) {
    s[i]=sw(s[i]), s[i-1]=sw(s[i-1]);
    ans.emplace_back(i,i+1);
  }
}

void rg(int i) {
  for (auto j = n-1; j > i; j--) {
    if (s[j]!=t[j]) {
      ans.emplace_back(i+1, j+1);
      for (auto k = i; k < j+1; k++) s[k]=sw(s[k]);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n;
    cin >> s >> t;
    ans.resize(0);
    int xd = n / 2-2;
    //transform
    if (trs(xd++) or trs(xd++) or trs(xd++)) 
      peer(xd--);
    else {
      xd = n/2-2;
      ans.emplace_back(xd+2, xd+2+2);
      s[xd+1]=sw(s[xd+1]);
      s[xd+2]=sw(s[xd+2]);
      s[xd+3]=sw(s[xd+3]);
      peer(xd);
    }
    //find
    auto p = t.find("00");
    if (p != string::npos) {
      xd = int(p);
      lf(xd), rg(xd);
    } else if ((p=t.find("11"))!=string::npos) {
      xd = int(p);
      lf(xd), rg(xd);
    } else {
      //cout <<"ga\n'";
      t[1]=sw(t[1]);
      t[2]=sw(t[2]);
      t[3]=sw(t[3]);
      rg(0);
      ans.emplace_back(2,4);
    }
    cout << sz(ans)<<'\n';
    for(auto& [l,r]: ans) cout << l <<' '<<r<<'\n';
  }
}


