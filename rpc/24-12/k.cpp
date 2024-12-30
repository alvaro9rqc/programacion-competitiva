#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

string trah(string s) {
  string s2(s.size(),'0');
  char c='0';
  for (auto i = 0; i < s.size(); ++i) {
    if (s[i]=='p') c='q';
    else if (s[i]== 'q')c='p';
    else if (s[i]=='b')c='d';
    else c='b';
    s2[s.size()-i-1]=c;
  }
  return s2;
}

void trav(string& s) {
  char p = 'o';
  for (auto i = 0; i < s.size(); ++i) {
    if (s[i]=='b') p = 'p';
    else if (s[i]=='d') p='q';
    else if (s[i]=='q')p='d';
    else p='b';
    s[i]=p;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, t;
  getline(cin,s);
  getline(cin,t);
  int v, h; v=h=0;
  for(auto& c: t) {
    if (c == 'h') {
      h++; h%=2;
    }else if (c=='v'){
      v++; v%=2;
    }else {
      h++;v++;
      h%=2;v%=2;
    }
  }
  if (h) s = trah(s);
  if (v) trav(s);
  cout << s<<'\n';
  return 0;
}


