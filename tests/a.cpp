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

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vi a = {7,2,3,4,5};
  auto p = a.begin();
  auto pr = --reverse_iterator(p);
  auto pr1 = --make_reverse_iterator(p);
  cout << "p: " << *p << " pr " << *pr << '\n';
  if (a.rend()-1 == pr1) cout << "igual\n";
  else cout << "no igual\n";
}


