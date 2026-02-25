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
  ll Q; cin >> Q;
  vector<ll> a = {0};
  ll idx = 0;
  ll res = 0;
  while(Q--) {
    int qn; int qt;
    cin >> qn;
    if(qn == 1) {
      cin >> qt; 
      a.push_back(a.back() + qt);
    } else if(qn == 2) {
      if (idx < a.size()-1)
        ++idx;
    } else {
      cin >> qt;
      cout << a[idx + qt] - a[idx] - (a[idx+qt] - a[idx+qt-1])<<'\n';
    }
  }
}


