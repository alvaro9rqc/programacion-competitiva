#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; string s; cin >> n >> k >> s;
  int ze = 0;
  int ones = 0;
  int block = 0;
  bool f=false;
  string ans="";
  int i=0;
  for(i; i < n; ++i) {
    if (f) {
      if (s[i]=='0') {
        //cout << "-> "<<ze<<'\n';
        f=false;
        ++block;
        if (block == k) {
          ans.append(string(ones,'1'));
          ans.append(string(ze,'0'));
        } else {
          ans.append(string(ze,'0'));
          ans.append(string(ones,'1'));
        }
        ze=0;ones=0;
        i--;
      } else ones++;
    } else {
      if (s[i]=='0') ze++;
      else {
        ones=1;
        f=true;
      }
    }
  }
  if (f and ++block == k) {
    ans.append(string(ones,'1'));
    ans.append(string(ze,'0'));
  } else {
    ans.append(string(ze,'0'));
    ans.append(string(ones,'1'));
  }
  cout << ans<<'\n';
  return 0;
}


