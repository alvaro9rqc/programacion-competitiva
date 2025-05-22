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

void f(int orr, int oc, int d, int pr, int pc, int i) {
  if (d == 1) {
    if (put[i] == g[pr][pc]) i = (i+1) %3;
    char t = g[pr][pc];
    g[orr][oc] = g[orr][oc+1] = put[i];
    g[orr+1][oc] = g[orr+1][oc+1] = put[i];
    g[pr][pc] = t;
  } else {
    if (pr < orr + d) {
      //.x
      //xx
      if ( pc < oc + d ) {
        //11
        f(orr, oc, (d>>1), pr, pc, i);
        int j = g[orr+d-1][oc+d-1] - 'A';
        j = (j+1) %3;
        int k = (j+1) % 3; 
        //12
        g[orr+d-1][oc+d] = put[j];
        f(orr, oc+d, (d>>1), orr+d-1, oc+d, k);
        //21
        g[orr+d][oc+d-1] = put[j];
        f(orr+d, oc, (d>>1), orr+d, oc+d-1, k);
        //22
        g[orr+d][oc+d] = put[j];
        f(orr+d, oc+d, (d>>1), orr+d, oc+d, i);
      } else {
        //12
        f(orr, oc+d, (d>>1), pr, pc, i);
        int j = g[orr+d-1][oc+d] - 'A';
        j = (j+1) %3;
        int k = (j+1) % 3; 
        //11
        g[orr+d-1][oc+d-1] = put[j];
        f(orr, oc, (d>>1), orr+d-1, oc+d-1, k);
        //21
        g[orr+d][oc+d-1] = put[j];
        f(orr+d, oc, (d>>1), orr+d, oc+d-1, i);
        //22
        g[orr+d][oc+d] = put[j];
        f(orr+d, oc+d, (d>>1), orr+d, oc+d, k);
      }
    } else {
      //xx
      //.x
      if ( pc < oc + d ) {
        //21
        f(orr+d, oc, (d>>1), pr, pc, i);
        int j = g[orr+d][oc+d-1] - 'A';
        j = (j+1) %3;
        int k = (j+1) % 3; 
        //11
        g[orr+d-1][oc+d-1] = put[j];
        f(orr, oc, (d>>1), orr+d-1, oc+d-1, k);
        //12
        g[orr+d-1][oc+d] = put[j];
        f(orr, oc+d, (d>>1), orr+d-1, oc+d, i);
        //22
        g[orr+d][oc+d] = put[j];
        f(orr+d, oc+d, (d>>1), orr+d, oc+d, k);
      } else {
        //22
        f(orr+d, oc+d, (d>>1), pr, pc, i);
        int j = g[orr+d][oc+d] - 'A';
        j = (j+1) %3;
        int k = (j+1) % 3; 
        //11
        g[orr+d-1][oc+d-1] = put[j];
        f(orr, oc, (d>>1), orr+d-1, oc+d-1, i);
        //12
        g[orr+d-1][oc+d] = put[j];
        f(orr, oc+d, (d>>1), orr+d-1, oc+d, k);
        //21
        g[orr+d][oc+d-1] = put[j];
        f(orr+d, oc, (d>>1), orr+d, oc+d-1, k);
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
  f(0, 0, n/2, r-1, c-1, 0);
  for(auto& s: g) 
    cout << s <<'\n';

}


