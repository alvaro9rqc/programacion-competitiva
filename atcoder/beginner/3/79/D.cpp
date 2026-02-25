#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  long q;
  cin >> q;
  vector<long long> v(q+1,0);
  v[0] = 0;
  queue<long> que;
  for(long i = 0; i < q; ++i){
    int op;
    cin >> op;
    if (op == 1) {
      que.push(i);
      v[i+1] = v[i];
    } else if (op == 2) {
      long x; cin >> x;
      v[i+1] = v[i] + x;
      //cout << "-> " << i << '\n';
    } else {
      v[i+1] = v[i];
      long long x; cin >> x;
      long c = 0;
      while (! que.empty()) {
        long temp = que.front();
        //cout << "-> " << v[ temp ] << " " << v[i] << '\n';
        if (v[i] - v[temp] >= x) {
          c++; que.pop();
        } else break;
      }
      cout << c << '\n';
    }
  }
  return 0;
}


