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

template <typename T>
ll f(T b, T e, vl&po, vl& ne) {
  stack<T> gr, lw;
  ll ans = 0;
  auto pit = po.begin();
  auto nit = ne.begin();
  for (auto i = b; i < e; ++i, ++pit, ++nit) {
    // menor
    while (not(lw.empty()) and *(lw.top()) >= *i) {
      lw.pop();
    }
    ll d;
    if (lw.empty()) d = ll(i-b+1);
    else d = ll( i - lw.top() );
    *nit*=d;
    lw.push(i);
    while (not (gr.empty()) and *(gr.top()) <= *i) {
      gr.pop();
    }
    if (gr.empty()) d = ll(i-b+1);
    else d = ll(i - gr.top());
    //cerr<<d<<"  ";
    //ans += d*(*i);
    *pit*=d;
    gr.push(i);
  }
  return ans;
}

template <typename T>
ll f2(T b, T e, vl&po, vl& ne) {
  stack<T> gr, lw;
  ll ans = 0;
  auto pit = po.rbegin();
  auto nit = ne.rbegin();
  for (auto i = b; i < e; ++i, ++pit, ++nit) {
    // menor
    while (not(lw.empty()) and *(lw.top()) > *i) {
      lw.pop();
    }
    ll d;
    if (lw.empty()) d = ll(i-b+1);
    else d = ll( i - lw.top() );
    *nit*=d;
    //cerr<< d << "  ";
    lw.push(i);
    while (not (gr.empty()) and *(gr.top()) < *i) {
      gr.pop();
    }
    if (gr.empty()) d = ll(i-b+1);
    else d = ll(i - gr.top());
    //cerr<<d<<"  ";
    //ans += d*(*i);
    *pit*=d;
    gr.push(i);
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vl a(n); 
  for(auto& e: a) cin >> e;
  vl pos(n,1), neg(n,1);
  ll ans = 0;
  ans += f(a.begin(), a.end(), pos, neg);
  ans += f2(a.rbegin(), a.rend(), pos, neg);
  for (auto i = 0; i < n; ++i) {
    //cerr << neg[i] << ' ';
    ans += pos[i]*a[i];
    ans -= neg[i]*a[i];
  }
  cout << ans << '\n';
  
}


