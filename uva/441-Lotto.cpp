#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi v(13);
vi l;
int k;

void backtraking(int i, int tam) {
  if (tam == 0) {
    for (int j = 0; j < 5; ++j) cout << l[j] << ' ';
    cout << l[5] <<  '\n';
  } else {
    while (k - i >= tam) {
      l.push_back(v[i]);
      backtraking(++i, tam-1);
      l.pop_back();
    }

  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin >> k;
  while (k) {
    v.assign(k, 0);
    for (int i = 0; i < k; ++i) cin >> v[i];
    backtraking(0, 6);
    cin >> k;
    if (k) cout << '\n';
  }
  return 0;
}


