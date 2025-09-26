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

char put[]= {'A', 'B', 'C'};

vector<string> g;

void f(int orr, int oc, int d, int pr, int pc, char x) {
  if (d == 1) {
    char t = g[pr][pc];
    g[orr][oc] = g[orr][oc+1] = x;
    g[orr+1][oc] = g[orr+1][oc+1] = x;
    g[pr][pc] = t;
  } else {
    if (pr < orr + d) {
      //.x
      //xx
      if ( pc < oc + d ) {
        //11
        f(orr, oc, (d>>1), pr, pc, 'A');
        //12
        g[orr+d-1][oc+d] = 'B';
        g[orr+d][oc+d-1] = 'B';
        g[orr+d][oc+d] = 'B';
        f(orr, oc+d, (d>>1), orr+d-1, oc+d, 'C');
        //21
        f(orr+d, oc, (d>>1), orr+d, oc+d-1, 'C');
        //22
        f(orr+d, oc+d, (d>>1), orr+d, oc+d, 'A');
      } else {
        g[orr+d-1][oc+d-1] = 'B';
        g[orr+d][oc+d-1] = 'B';
        g[orr+d][oc+d] = 'B';
        //12
        f(orr, oc+d, (d>>1), pr, pc, 'C');
        //11
        f(orr, oc, (d>>1), orr+d-1, oc+d-1, 'A');
        //21
        f(orr+d, oc, (d>>1), orr+d, oc+d-1, 'C');
        //22
        f(orr+d, oc+d, (d>>1), orr+d, oc+d, 'A');
      }
    } else {
      //xx
      //.x
      if ( pc < oc + d ) {
        //21
        f(orr+d, oc, (d>>1), pr, pc, 'C');
        //11
        g[orr+d-1][oc+d-1] = 'B';
        f(orr, oc, (d>>1), orr+d-1, oc+d-1, 'A');
        //12
        g[orr+d-1][oc+d] = 'B';
        f(orr, oc+d, (d>>1), orr+d-1, oc+d, 'C');
        //22
        g[orr+d][oc+d] = 'B';
        f(orr+d, oc+d, (d>>1), orr+d, oc+d, 'A');
      } else {
        //22
        f(orr+d, oc+d, (d>>1), pr, pc, 'A');
        //11
        g[orr+d-1][oc+d-1] = 'B';
        f(orr, oc, (d>>1), orr+d-1, oc+d-1, 'A');
        //12
        g[orr+d-1][oc+d] = 'B';
        f(orr, oc+d, (d>>1), orr+d-1, oc+d, 'C');
        //21
        g[orr+d][oc+d-1] = 'B';
        f(orr+d, oc, (d>>1), orr+d, oc+d-1, 'C');
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  g.assign(n, string(n, '.'));
  int r, c; cin>>r>>c;
  if (n == 1) {
    cout << ".\n";
    return 0;
  }
  f(0, 0, n/2, r-1, c-1, 'A');
  for(auto& s: g) 
    cout << s <<'\n';

}


