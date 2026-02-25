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
  int N; cin >> N;
  unordered_set<int> s;
  vi dif(N);
  int su = 0;
  int ans = 0;
  for (auto i = 0; i < N; ++i) {
    int x; cin >> x; 
    s.insert(x);
    dif[i] = s.size();
    su += dif[i];
  }
  ans = su;
  int acs = 0;
  int mul = 0;
  for (auto i = 1; i < N; ++i) {
    acs += dif[i-1];
    if (dif[i-1] != dif[i]) mul++;
    ans += su - acs - ( N - i )* mul;
  }
  cout << ans <<'\n';
  return 0;
}


