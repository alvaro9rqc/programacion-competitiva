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
    string d = "";
    cout << "? 0" << endl;
    int tr; cin >> tr;
    if(tr) d = "0";
    else d = "1";
    while (int( d.size() ) < n){
      cout << "? " << "0" << d << endl;
      int r; cin >> r;
      if (r) {
        d = "0" + d;
        continue;
      }
      cout << "? " << "1" << d << endl;
      cin >> r;
      if (r){
        d = "1" + d;
        continue;
      }
      break;
    }
    while(int( d.size() ) < n) {
      cout << "? " << d << "0" << endl;
      int r; cin>> r;
      if (r) d.push_back('0');
      else d.push_back('1');
    }
    cout << "! " << d << endl;
  }
}


