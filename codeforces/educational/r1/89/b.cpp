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

vi fid(string& s) {
  vi ids;
  for (auto i = 1; i < sz(s); i++) {
    if(s[i]==s[i-1])ids.emplace_back(i);
  }
  return ids;
}

pair<vi,vi> alt(string& s, int l, int r) {
  auto s2 = s;
  auto s3 = s;
  for (auto i = l; i < r; i++) 
    if(s3[i]=='a')s3[i]='b';
  else s3[i]='a';
  reverse(s2.begin()+l,s2.begin()+r);
  reverse(s3.begin()+l,s3.begin()+r);
  return {fid(s2),fid(s3)};
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    string s;cin>>s;
    auto id1=fid(s);
    if(sz(id1)==0){
      cout<<"yes\n";continue;
    }
    if(sz(id1)==1) id1.emplace_back(sz(s));
    auto [id2,id3]=alt(s,id1.front(),id1.back());
    cout<< ((sz(id2)==0 or sz(id3)==0)?"yes":"no")<<'\n';
  }
}

