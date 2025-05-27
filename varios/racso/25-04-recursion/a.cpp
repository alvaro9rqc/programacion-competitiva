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

void hanoi(int n, char s, char m, char d) {
  if (n == 1) {
    cout << "Move from " << s << " to " << d << ".\n";
  } else {
    hanoi(n-1, s, d, m);
    cout << "Move from " << s << " to " << d << ".\n";
    hanoi(n-1, m, s, d);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt; cin >> tt; 
  while(tt--) {
    int n; cin >> n;
    char s, m, d; cin >> s >>  d;
    if ((s == 'A' and d == 'B') or (d == 'A' and s == 'B')) m = 'C';
    if ((s == 'A' and d == 'C') or (d == 'A' and s == 'C')) m = 'B';
    if ((s == 'C' and d == 'B') or (d == 'C' and s == 'B')) m = 'A';
    hanoi(n, s, m, d);
    cout << "Done!\n";
  }
  /*
   * Mira, puede mover un a un c. 
   * si tienes un disco, lo mueves a c.
   * tienes dos. 
   *    para el de más arriba, el medio es el nuevo c, y el c es el medio
   *
   * */ 
}


