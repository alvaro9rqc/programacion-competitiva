#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  vector<long> v(50000+1);
  v[1]=1;
  for (long i = 2; i < v.size(); i++) 
    v[i] = i*i*i + v[i-1];
  int x;
  while (cin>>x){
    cout << v[x]<<'\n';
  }
  return 0;
}


