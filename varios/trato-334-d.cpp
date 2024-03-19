#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n, q;
  cin >> n << q;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i]; 
  }
  //1. ordenar el array
  sort(a.begin(), a.end());
  //2. la prefixSuma de prefijos. calcular el array
  vector <int> prefixSum (n);
  prefixSum[0] = a[0];
  for (int i = 1; i < n; i++) {
    prefixSum[i] = a[i] + prefixSum[i -1]; 
  }
  for (int i = 0; i < q; i++) {
    int w;
    cin >> w;
    //3. hacer la búsqueda binaria para cada w
    int  it = upper_bound(prefixSum.begin(), prefixSum.end(), w) - prefixSum.begin();
    // se obtiene la posición en índices
    cout << it << '\n';
  }
  return 0;
}

