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

void solve() {
  int n;cin>>n;
  if(n==1) {
    cout<<"1\n";return;
  }
  string s(n,'0');
  int q = (n+1)/3;
  if ((n+1)%3==0) {
    if(q&1) s[0]=s[q]=s[2*q-1]='1';
    else s[q-1]=s[2*q-1]='1';
  } else if ((n+1)%3==1) {
    if(q&1)s[q-1]=s[2*q]='1';
    else s[q-1]=s[2*q-1]='1';
  } else {
    if(q&1) s[q]=s[2*q+1]='1';
    else s[q]=s[2*q]='1';
  }
  reverse(all(s));
  cout<<s<<'\n';
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

