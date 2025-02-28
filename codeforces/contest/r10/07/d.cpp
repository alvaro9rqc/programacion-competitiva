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

ll T, N, L, R;

vll A;
vll S;

ll busqueda(ll i) {
  if(i <= N) {
    //if (i >= S.size())
    //  cout << "oh no " << i <<' ' << S.size() <<'\n ';
    return A[i];
  }
  //return -1;
  ll r = i / 2;
  if (r <= N) {
    return S[r];
  }
  if(r % 2 == 1) {
    return S.back();
  } else {
    return S.back() ^ busqueda(r);
  }

}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T; 
  while(T--) {
    cin >> N >> L >> R;
    A.assign(N+1, 0);
    S.assign(N+1, 0);
    for (ll i = 1; i <= N; ++i) {
      cin >> A[i];
      S[i] = A[i]^S[i-1];
    }
    if(N%2 == 0) {
      A.push_back(S[N/2]);
      S.push_back(A.back()^S[N]);
      N++;
    }
    //for(auto& s: S) cout << s <<' ';
    //cout << '\n';

    cout << busqueda(L) << '\n';
  }
}


