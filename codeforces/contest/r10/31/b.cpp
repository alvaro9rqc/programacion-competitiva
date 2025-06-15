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
  ll tt; cin >> tt;
  while(tt--){
    ll w, h, a, b; 
    cin>> w>>h>>a>>b;
    ll x1,x2,y1,y2;
    cin >> x1>>y1>>x2>>y2;
    bool can= true;
    // vert
      ll dx ;
      ll dy;
    dx = ll(abs(x1-x2));
    dy = ll(abs(y1-y2));
    if ( 
        (y1 <= y2 and y2 < y1+b) or 
        (y1 < (y2+b) and (y2+b) <= y1+b) 
        ) {
      //if (x1 < x2) dx = x2 -(x1+a);
      //else dx = x1 - (x2+a);
      if (dx % a) can = false;
    }
    //cerr << "ga" << can << '\n';
    if (
        (x1 <= x2 and x2 < x1+a) or
        (x1 < (x2+a) and (x2+a) <= x1+a) 
        ) {
      //if (y1 < y2) dy = y2 - (y1+b);
      //else dy = y1 - (y2+b);
      if (dy % b) can = false;
    }
    if (dy%b and dx%a) can = false;
    //cout << ((dy%b and dx%a)?"No":"Yes") << '\n';
    cout << (can?"Yes":"No")<<'\n';
    // hor

  }
}


