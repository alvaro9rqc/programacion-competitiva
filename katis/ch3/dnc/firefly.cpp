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
  int N,H;
  cin >> N >> H;
  vi up(N/2);
  vi down(N/2);
  for (int i = 0; i < N; ++i) {
    if(i&1) cin >> up[i/2];
    else cin >> down[i/2];
  }
  sort(up.begin(),up.end() );
  sort(down.begin(),down.end());
  map<int,int>m;
  for (int i = 1; i <= H; ++i) {
    int d = (int)(down.end() - lower_bound(down.begin(),down.end(), i));
    int u = (int)(up.end() - lower_bound(up.begin(),up.end(), H-i+1));
    //cout <<i<<' '<< d <<' ' << u <<'\n';
    //int u = (int)(upper_bound(up.begin(),up.end(), i) - up.begin());
    m[d+u]++;
  }
  auto it = m.begin();
  cout << it->first <<' '<<it->second <<'\n';
}


