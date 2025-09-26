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

int n, k;
vi e(30);
vi ans(30);

void c(int i, int j) {
  if (not (j < k)) {
    cout << '{';
    for (auto l = 0; l < k; ++l) cout << ans[l] << (l!=k-1 ? ",":"");
    cout << "}\n";
  } else{
    for (auto l = i; l < n-k+j+1; ++l) {
      ans[j] = e[l];
      c(l+1, j+1);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n >> k;
    for (auto i = 0; i < n; ++i) {
      cin >> e[i];
    }
    sort(e.begin(), e.begin() + n);
    c(0, 0);
    cout << "---\n";
  }
}


