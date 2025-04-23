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

void print(int i, vi p, vi s) {
  if (p[i] == -1) {
    cout << s[i] << '\n';
    return;
  }
  print(p[i], p, s);
  cout << s[i] << '\n';
}


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vi s;
  for (int x; cin >> x; s.push_back(x));
  vi l(s.size());
  vi l_idx(s.size());
  vi p(s.size());
  int k = 0;
  int lat;
  for (auto i = 0u; i < s.size(); ++i) {
    int pos = int( lower_bound( l.begin(), l.begin() + k, s[i]  ) - l.begin() );
    l[pos]=s[i];
    l_idx[pos] = i;
    p[i] = pos ? l_idx[pos-1]:-1;
    if (pos == k) ++k,lat=i;
  }
  int idx = 0;
  while(true) {
    l[idx++] = s[lat];
    if (p[lat]==-1)break;
    lat = p[lat];
  }
  cout << k << "\n-\n";
  for (auto i = k-1; i > -1; --i) {
    cout << l[i] << '\n';
  }
}


