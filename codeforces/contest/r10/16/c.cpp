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
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

const ll LIM = 1e5;
bitset<LIM> bs;
vector<ll> p;

void crive(){
  bs.set();
  bs[0]=bs[1]=0;
  for (ll i = 2; i < LIM; ++i) {
    if (bs[i]) {
      for (ll j = i*i; j < LIM; j +=i) {
        bs[j]=0;
      }
      p.push_back(i);
    }
  }
}

bool prime(ll n){
  if(n <LIM) return bs[n];
  for(auto& pr: p) {
    if (n % pr == 0) return false;
  }
  return true;
}

ll gen(ll x, ll k) {
  string a = to_string(x);
  string n;
  for (ll i = 0; i < k; ++i) {
    n += a;
  }
  return stoll(n);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  crive();
  //for(auto& pr: p) {
  //  cout << pr << ' ';
  //}
  //cout << '\n';
  int t; 
  cin >> t;
  while(t--){
    ll x, k;
    cin >> x >> k;
    if(k >= 2 and x != 1){
      cout << "NO\n";
    } else if (x == 1){ 
      ll n = gen(x, k);
      cout << (prime(n)? "YES\n":"NO\n");
    }
    else  {
      cout << (prime(x)? "YES\n":"NO\n");
    }
  }
}


