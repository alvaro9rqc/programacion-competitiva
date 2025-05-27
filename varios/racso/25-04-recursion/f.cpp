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

int f(int wl, int dl, int wr, int dr) {
  cin >> wl >> dl >> wr >> dr;
  if (wl == 0) {
    wl = f(0,0,0,0);
  } 
  if (wr == 0) 
    wr = f(0,0,0,0);
  if (wl == -1 or wr == -1) return -1;
  if (wl*dl != wr*dr) return -1;
  else return wl + wr;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt; cin >> tt;
  while(tt--) {
    int ans = f(0,0,0,0);
    cerr<<ans <<'\n';
    if (ans == -1) cout << "NO\n";
    else cout << "YES\n";
  }
}


