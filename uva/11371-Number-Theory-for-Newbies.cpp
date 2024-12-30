#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void wt0(string &a) {
  for (auto i = 0; i < a.size(); ++i) {
    if (a[i] != '0') {
      a = a.substr(i,a.size()-i);
      break;
    }
  }
}

void can0(string &a) {
  for (auto i = 0; i < a.size(); ++i) {
    if (a[i]!='0') {
      swap(a[i],a[0]);
      break;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  while (cin >> a) {
    wt0(a);
    sort(a.begin(), a.end());
    b = a;
    sort(b.begin(), b.end(), greater<char>());
    can0(a);
    ll na = stoll(a);
    ll nb = stoll(b);
    cout << nb << " - "<<na<<" = "<<nb-na<<" = "<< 9 << " * "<<(nb - na)/9<<'\n';
  }
  return 0;
}


