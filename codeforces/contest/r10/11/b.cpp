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
  int t; 
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    //cout << "err "<<n<<'\n';
    vi a(n);
    int c0 = 0;
    for(auto& e: a) {
      cin >> e;
      if (e ==0) ++c0;
    }
    if (c0 == 0) {
      cout << 1 <<'\n';
      cout << 1 << ' '<< n<<'\n';
    } else if (c0 == 1) {
      for (auto i = 0; i < n; ++i) {
        if (a[i]==0) {
          cout << 2 << '\n';
          if (i ==0) {
            cout << 1 << ' '<<2<<'\n';
          } else {
            cout << i << ' '<<i+1<<'\n';
          }
          cout << 1 << ' '<<n-1<<'\n';
          break;
        }
      }
    } else {
      //ultimo caso
      int p0=-1, s0;
      for (auto i = 0; i < n; ++i) {
        if (a[i]==0) {
          if (p0==-1) p0=i;
          else {
            s0=i;
            break;
          }
        }
      }
      //consecutivo
      if (p0==s0-1) {
        if (c0 == 2) {
          cout << 2 << '\n';
          cout << p0+1<<' '<<s0+1<<'\n';
          cout << 1<<' '<<n-1<<'\n';
        } else {
          cout << 3 << '\n';
          if (p0==0) {
            cout << "1 2"<<'\n';
            cout << 2<<' '<<n-1<<'\n';
          } else {
            cout << 1<<' '<<p0+1<<'\n';
            cout << 2 << ' '<<n-p0<<'\n';
          }
          cout << "1 2\n";
        }
        continue;
      } else {
        //no consecutivbos
        cout << 3 << '\n';
        if (p0==0) {
          cout << "1 2\n";
          cout << '2'<<' '<<n-1<<'\n';
        } else {
          cout << 1<<' '<<p0+1<<'\n';
          cout << 2 << ' '<<n-p0<<'\n';
        }
        cout << "1 2\n";
      }
    }

  }
}


