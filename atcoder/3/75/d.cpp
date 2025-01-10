#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string S; cin >> S;
  unordered_map<char,vi> m(S.size());
  for (auto i = 0; i < S.size(); ++i) {
    m[S[i]].push_back(i+1);
  }
  ll ans = 0;
  for(auto& [k, v]: m) {
    ll sum = 0;
    for (auto i = 1; i < v.size(); ++i) {
      sum += v[i] - v[0] - 1;
    }
    ll lans = sum;
    for (auto i = 1; i < v.size()-1; ++i) {
      sum -= (v.size() - i) * (v[i] - v[i-1])-1 ;
      lans += sum;
    }
    ans += lans;
    //cout << k << ' ' << lans << '\n';
  }
  cout << ans<<'\n';
  return 0;
}


