#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;

string s;
int used[11] = {0};
string ans;

int sea(char x) {
  int y = x - '0';
  for (auto i = y; i >= 0 ; --i) {
    if (used[i] < 3) return i;
  }
  return -1;
}

void f(int t, int i) {
  if (not( i < int(s.size())-1 )) {
    int x = sea(s[i]);
    if (x == -1) f(1, i-1);
    else {
      ans.push_back(s[i]);
      return;
    }
  } else if (t == 0) {
    int x = sea(s[i]);
    if (x == -1) f(1, i-1);
    else ++used[x], ans.push_back(s[i]), f(0, i+1);
  } else{
    used[s[i]-'0']--;
    ans.pop_back();
    int x = sea(s[i]-1);
    if (x == 0 and i == 0) {
      used[9]++;
      ans = "9";
      for (auto k = 1; k < int(s.size()); ++k) {
        x = sea('9');
        ans.push_back(char(x + '0'));
        used[x]++;
      }
    } else {
      used[x]++;
      ans.push_back(char(x+'0'));
      for (auto k = i+1; k <int(s.size()); ++k) {
        x = sea('9');
        ans.push_back(char(x+'0'));
        used[x]++;
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while(cin >> s) {
    for (auto i = 0; i < 11; ++i) {
      used[i] = 0;
    }
    ans = "";
    f(0,0);
    cout << ans << '\n';
  }
}


