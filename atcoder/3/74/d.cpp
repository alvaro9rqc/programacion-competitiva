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
  int N, S, T; cin >> N >> S >> T;
  vector<tuple<int,int,int,int>> pts(N);
  for(auto& [a,b,c,d]: pts) {
    cin >> a>>b>>c>>d;
  }
  vi v(N);
  iota(v.begin(),v.end(),0);
  double ans = DBL_MAX;
  auto mov= [&](int& x, int&y, int a, int b, int c, int d) {
    double time =0;
    time += sqrt( (a-x)*(a-x) + (b-y)*(b-y) ) / S;
    time += sqrt( (c-a)*(c-a) + (d-b)*(d-b) ) / T;
    x = c;
    y = d;
    return time;
  };
  do{
    for (auto i = 0; i < (1<<N); ++i) {
      int x=0,y=0;
      double lan = 0;
      for (auto j = 0; j < N; ++j) {
        auto [a,b,c,d] = pts[ v[j] ];
        if (i & (1<<j)) {
          swap(a,c);
          swap(b,d);
        }
        lan+= mov(x,y,a,b,c,d);
        //cout << mov(x,y,a,b,c,d)<<'\n';
      }
      //cout << "-> " << lan <<'\n';
      ans = min(ans, lan);
    }
  } while(next_permutation(v.begin(), v.end()));
  //cout << ans <<'\n';
  printf("%0.6lf\n", ans);
  return 0;
}


