#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

//long memo[27][10001][10001];
vector<map<tuple<int,int>,long> >memo(27);

// La cantidad de coliciones comenzando con c, con longitud l y suma s
// 3 10
long x (int c,int l, int s) {
  if (l == 1 ) return (c <= s && s <= 26)? 1:0;
  if (( s < c + l -1 )  || s - c > (l-1)*26) return 0; 
  if (memo[c].find({l,s}) != memo[c].end()) return memo[c][{l,s}];
  long sum = x(c+1, l, s) + x (c+1, l-1, s-c);
  return memo[c][{l,s}] = sum;
}


int main () {
  ios_base::sync_with_stdio(false);
  int t=0;
  int l, s;
  //memset(memo, -1, sizeof memo);
  while (cin >> l >> s) {
    if (l == 0 && s == 0 ) break;
    cout << "Case " << ++t << ": " << x(1, l, s) << '\n';
  }
  return 0;
}


