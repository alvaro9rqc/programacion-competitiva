#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void bach(ll n) {
  if ((n % 2) == 1 or (n % 2) == -1) {
    ll a, b;
    a = (n + 1) / 2;
    b = n - a;
    a = abs(a);
    b = abs(b);
    cout << a <<' '<< b<<'\n';
  } else if (n % 4 == 0) {
    ll a, b;
    a = (n / 2 + 2) / 2;
    b = n / 2 - a;
    a = abs(a);
    b = abs(b);
    cout << a << ' '<<b<<'\n';
  }
  else {
    if (n % 2== 0) 
      cout << "Bachelor Number.\n";
    else 
      cout << "Spinster Number.\n";
  }
}

ll f(ll n) {
  if (n < 0) return 0;
  //if (n == 0) return 1;
  ll t = n - n / 2;
  return t + n /4+1;
}

void ran(ll a, ll b) {
  cout <<b -a+1 -( f(b) - f(a-1) )<<'\n';
}
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, n2;
  string line;
  while (getline(cin, line)) {
    //cout <<"-> "<< line <<'\n';
    cin >> ws;
    stringstream s(line);
    s >> n;
    n2 = -1;
    s >> n2;
    if (n2 == -1) {
      bach(n);
    } else {
      ran(n, n2);
    }
  }
  return 0;
}


