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


int is_day = -1;

unordered_map<char, int> seres;
vector<char> li;
unordered_map<char, vector<tuple<char,string,bool>>> statement;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int nro = 0;
  while(cin >> n >> ws) {
    seres.clear();
    statement.clear();
    if (n==0) break;
    for (auto i = 0; i < n; ++i) {
      string s; getline(cin, s);
      //cout <<"-> " << s <<'\n';
      stringstream inp(s);
      char x; inp >> x;
      char c; inp >> c;
      string sub; 
      inp >> sub;
      if (sub != "It") {
        char suj = sub[0];
        if (sub == "I") suj = x;
        string par;
        inp >> par;
        inp >> par;
        if (par == "not") {
          inp >> par;
          statement[x].push_back( {suj, par, false} );
        } else statement[x].push_back( {suj, par, true} );
      } else {
        inp >> sub;
        inp >> sub;
        statement[x].push_back( {'d',sub, true } );
      }
    }
    cout << "Conversation #"<<++nro <<'\n';
    li.clear();
    for(auto& [k,v]: statement) {
      li.push_back(k);
    }

    //for(auto& [k, st]: statement) {
    //  for(auto& [s,t,b]: st) {
    //    cout <<k<<' '<< s <<' ' << t <<' ' << b <<'\n';
    //  }
    //}
  }
}


