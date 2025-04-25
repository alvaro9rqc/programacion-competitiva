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

bool s(int a, int b, vi& v1, vi& v2) {
  if (v1[a] == v1[b]) {
    return v2[a] < v2[b];
  }
  return v1[a] < v1[b];
}

int f(vi&v, vi& id) {
  int n = int(v.size());
  vi l(n);
  int idx = 0;
  int k = 0;
  for (auto i = 0; i < n; ++i) {
    idx = id[i];
    int pos = int( upper_bound( l.begin(), l.begin()+k, v[idx] )-l.begin() );
    l[pos]=v[idx];
    if (pos == k) ++k;
  }
  return k;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while(1) {
    int n; cin >> n;
    if (n == 0) break;
    vi L(n), M(n);
    for (auto i = 0; i < n; ++i) {
      int l, m; cin >> l >> m;
      L[i]=l;
      M[i]=m;
    }
    vi id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&L, &M](int a, int b){
        return s(a,b,L,M);
    });
    //for (auto i = 0; i < n; ++i) {
    //  cout << L[id[i]] <<' '<< M[id[i]] << '\n';
    //}
    //cout << '\n';
    int a1 = f(M, id);
    //sort(id.begin(), id.end(), [&L, &M](int a, int b){
    //    return s(a,b,M,L);
    //});
    //int a2 = f(L, id);
    cout << a1 << '\n';
  }
  cout << "*\n";
}


