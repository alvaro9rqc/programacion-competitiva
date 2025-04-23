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

vll A;
vll B;
vector<vll> g;
int t;
ll n;
vector<vll> bad;
bool can;
ll ans;

bool check_c(ll i, ll j){
  for (auto k = 0; k < n; ++k) 
    if (g[k][i] == g[k][j]) return false;
  return true;
}

bool check_r(ll i, ll j){
  for (auto k = 0; k < n; ++k) 
    if (g[i][k] == g[j][k]) return false;
  return true;
}

void bad_r(){
  for (auto i = 1; i < n; ++i) {
    if ( check_r(i, i-1)) continue;
    if (bad.empty()){
      bad.emplace_back();
      bad.back().push_back(i-1);
      bad.back().push_back(i);
    } else {
      if (bad.back().back() == i-1) bad.back().push_back(i);
      else {
        bad.emplace_back();
        bad.back().push_back(i-1);
        bad.back().push_back(i);
      }
    }
  }
}

void add_r(ll i){
  for(auto& e: g[i]) {
    e++;
  }
}

void add_c(ll i){
  for (auto k = 0; k < n; ++k) {
    ++g[k][i];
  }
}

bool c_i_r(ll i){
  if (i == 0) {
    return check_r(0,1);
  }else if(i==n-1) {
    return check_r(n-1,n-2);
  }
  return check_r(i,i-1) and check_r(i,i+1);
}

bool sol_r(vll& li, ll& inc){ 
  bool f = true;
  inc = 0;
  for (auto i = 0u; i < li.size(); i+=2) {
    add_r(li[i]);
    if (not c_i_r(li[i])) 
    {
      f = false;
      break;
    }
    inc+= A[li[i]];
  }
  ll inc2 = 0;
  for (auto i = 1u; i < li.size(); i+=2) {
    add_r(li[i]);
    add_r(li[i]);
    if (not c_i_r(li[i])) 
    {
      return f;
    }
    inc2 += A[li[i]];
  }
  if (f)inc = min(inc, inc2);
  inc = inc2;
  return true;
}

bool c_i_c(ll i){
  if (i == 0) {
    return check_c(0,1);
  }else if(i==n-1) {
    return check_c(n-1,n-2);
  }
  return check_c(i,i-1) and check_c(i,i+1);
}

bool sol_c(vll& li, ll& inc){ 
  bool f = true;
  inc = 0;
  for (auto i = 0u; i < li.size(); i+=2) {
    add_c(li[i]);
    if (not c_i_c(li[i])) 
    {
      f = false;
      break;
    }
    inc+= B[li[i]];
  }
  ll inc2 = 0;
  for (auto i = 1u; i < li.size(); i+=2) {
    add_c(li[i]);
    add_c(li[i]);
    if (not c_i_c(li[i])) 
    {
      return f;
    }
    inc2 += B[li[i]];
  }
  if (f) inc = min(inc, inc2);
  else inc = inc2;
  return true;
}

void bad_c(){
  for (auto i = 1; i < n; ++i) {
    if (check_c(i,i-1)) continue;
    if (bad.empty()){ 
      bad.emplace_back();
      bad.back().push_back(i-1);
      bad.back().push_back(i);
    }else {
      if (bad.back().back() == i-1) bad.back().push_back(i);
      else {
        bad.emplace_back();
        bad.back().push_back(i-1);
        bad.back().push_back(i);
      }
    }
  }
}



void columns(){
  bad.clear();
  bad_c();
  for(auto& li: bad) {
    ll inc = 0;
    if (not sol_c(li, inc)) {
      can = false;
      break;
    }
    ans += inc;
  }
}

void rows(){
  bad.clear();
  bad_r();
  for(auto& li: bad) {
    ll inc = 0;
    if (not sol_r(li, inc)) {
      can = false;
      break;
    }
    ans += inc;
  }
}


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while(t--){
    // read
    cin >> n;
    g.assign(n, vll(n));
    for(auto& r: g) 
      for(auto& c: r) cin >> c;
    A.assign(n, 0);
    B.assign(n,0);
    for(auto& e: A) cin >> e;
    for(auto& e: B) cin >> e;
    can = true;
    ans = 0;
    rows();
    //cout << "> " << can << '\n';
    columns();
    cout << (can ? ans:-1) <<'\n';
  }
}
