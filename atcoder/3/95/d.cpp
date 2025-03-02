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
  int N, Q;
  cin >> N >> Q;
  vi Pig(N);
  vi Nest(N);
  vi id(N);
  iota(Pig.begin(), Pig.end(), 0);
  iota(Nest.begin(), Nest.end(), 0);
  iota(id.begin(), id.end(), 0);

  while(Q--) {
    int t; cin>>t;
    if (t == 1) {
      int a, b; cin >> a >> b;
      --a,--b;
      Pig[a] = Nest[b];
    } else if (t == 2) {
      int a, b; cin >> a >> b;
      --a;--b;
      id[Nest[a]]=b;
      id[Nest[b]]=a;
      swap(Nest[a], Nest[b]);
    } else {
      int a; cin >> a;
      cout << id[Pig[a-1]]+1<<'\n';
    }
  }
}


