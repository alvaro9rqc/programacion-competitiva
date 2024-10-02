#include <bits/stdc++.h> 
using namespace std;
long p(int n, int e) {
  long x = 1;
  while (e--) {
    x *= n;
  }
  return x;
}

int main () {
  ios_base::sync_with_stdio(false);
  string line; int x, d,n;
  long sum;
  while (cin >> x) {
    sum = 0;
    cin.ignore();
    getline(cin , line);
    stringstream s(line);
    vector <int> a;
    while (s >> d)
      a.push_back(d);
    n = a.size()-1;
    //pow
    vector<long> v(n+1);
    v[0]=1;
    for (int i = 1; i< n; i++)
      v[i] = v[i-1]*x;
    //end pow
    for (int i = 0; i < n; i++) 
      sum += ( (long)( a[i] ) )*(n-i)*v[n-i-1];
    //sum += ( (long)( a[i] ) )*(n-i)*p(x, n-i-1);
    //sum += a[i]*(n-i)*(long)pow(x , n-i-1);
    //cout << line << ' ' << x << '\n';
    cout << sum << '\n';
  }
  return 0;
}


