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
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    string s; cin >> s;
    int gr=0,lo=0;
    for(auto& e: s) {
      if (e=='<') lo++;
      else ++gr;
    }
    int p = n - gr;
    cout << p++ <<' ';
    for(auto& e: s) {
      if (e == '<')cout << lo-- <<' ';
      else cout << p++ << ' ';
    }
    cout << '\n';
  }
}


