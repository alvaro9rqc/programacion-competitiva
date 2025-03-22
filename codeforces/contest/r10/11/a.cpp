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
  while(t--) {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    string ainv(a.rbegin(), a.rend());
    //cout << a <<' '<<ainv<<'\n';
    bool iss=true;
    char d = a[0];
    for(auto& e: a) {
      if (d!=e) {
        iss=false;
        break;
      }
    }

    if (iss) {
      cout << "NO\n";
    } else {
      if (a < ainv) {
        cout << "YES\n";
      } else {
        if (k == 0) cout << "NO\n";
        else cout << "YES\n";
      }
    }
  }
}


