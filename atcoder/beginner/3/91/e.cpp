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

int n;
vector<bool> a;
bool win;

pair<bool,ll> bt(ll l, ll idx) {
  //cout <<':'<<idx<<'\n';
  if(l == n) {
    return { a[idx], 1 };
  }
  auto[a, na] = bt(l+1,idx*3);
  auto[b, nb] = bt(l+1,idx*3+1);
  auto[c, nc] = bt(l+1,idx*3+2);
  //cout <<a<<b<<c<< ' '<<l<<' '<<idx<<'\n';
  if(a == b) {
    if (a == c) return { a, na+nb+nc - max(na,max(nb,nc)) };
    else return { a, min(na,nb) };
  } else {
    if (a == c) return { a, min(na, nc) };
    else return {b, min(nb,nc)};
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  string s; cin >> s;
  a.resize(s.size());
  for (auto i = 0; i < s.size(); ++i) {
    a[i]= s[i] - '0';
  }
  auto[w, a] = bt(0,0);
  cout <<a<<'\n';
}


