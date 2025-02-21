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
  int ans = 0;
  int N,M,K; cin >> N>>M>>K;
  vector<vi> t(M); vector<bool> r(M);
  for (auto i = 0; i < M; ++i) {
    int c; cin >> c;
    int xd;
    for (auto k = 0; k < c; ++k) {
      cin >> xd;
      t[i].push_back(xd);
    }
    char res; cin >> res;
    r[i] = res=='o';
  }
  for(int n = 0; n < (1<<N); ++n) {
    bool f = true;
    for (auto i = 0; i < M; ++i) {
      int count = 0;
      for(auto& b: t[i]) count += (n & (1<<(b-1)))?1:0;
      //cout << ": " << count<<'\n';
      if(count < K == r[i]) {
        f = false;
        break;
      }
    }
    ans+=f?1:0;
  }
  cout << ans <<'\n';
}
