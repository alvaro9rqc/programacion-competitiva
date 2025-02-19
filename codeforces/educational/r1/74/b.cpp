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

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--) {
    ll rows,cols; cin >> rows >> cols;
    vector<vll> g(rows, vll(cols));
    for(auto& r: g) {
      for(auto& c: r) {
        cin >> c;
      }
    }
    unordered_map<ll,ll> m;



    for (auto r = 0; r < rows; ++r) {
      for (auto c = r%2==0?0:1; c < cols; c+=2) {
        //cout << "-> " << r <<' ' << c <<'\n';
        if(m[g[r][c]] == 0) m[g[r][c]] = 1;
      }
    }




    auto has = [&g, &rows, &cols](int r, int c) {
      for (auto i = 0; i < 4; ++i) {
        int nr = r+dr[i], nc=c+dc[i];
        if ( 0 <= nr and nr <  rows and
            0 <= nc and nc < cols and 
            g[r][c] == g[nr][nc]
            ) return true;
      }
      return false;
    };

    //for(auto& [k,v]: m) {
    //  cout << k <<' '<<v<<'\n';
    //}
    //cout <<"------\n";

    for (auto r = 0; r < rows; ++r) {
      for (auto c = r%2==0?1:0; c < cols; c+=2) {
        if(m[g[r][c]] == 0) m[g[r][c]]++;
        else if (m[g[r][c]] == 1 and has(r,c)) m[g[r][c]]++;
      }
    }
    ll maxe = 0;
    ll sum = 0;
    for(auto& [k,v]: m) {
      maxe = max(v,maxe);
      sum+=v;
    }
    cout << sum - maxe <<'\n';
  }
}


