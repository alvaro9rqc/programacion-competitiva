#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll deg;

bool isd(string n) {
  deg++;
  //cout <<"-> "<<n<<'\n';
  if (n.size()==1) {
    return n[0] == '9';
  }
  ll x=0;
  for(auto& c: n) {
    x += (int)c -'0';
  }
  return isd(to_string(x));
}
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string line;
  while(cin >> line) {
    if (line.size() ==1 and line[0]=='0') break;
    deg = 0;
    bool f = isd(line);
    if (deg>1)--deg;
    if (f)
      cout << line << " is a multiple of 9 and has 9-degree "<<deg<<".\n";
    else 
      cout << line <<" is not a multiple of 9.\n";
  }
  return 0;
}


