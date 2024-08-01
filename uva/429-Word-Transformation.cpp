#include <bits/stdc++.h> 
#define INF (int)1e10
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  int n;
  string w, dum;
  cin >> n;
  getline(cin , dum);
  getline(cin , dum);
  while (n--) {
    //getline(cin , w);
    unordered_map <string, int> m;
    int i =0 ;
    vector< vector<string> > g;
    while ( getline(cin , w) ) {
      //cout << "," << w << ',';
      if (w[0] == '*')break;
      g.push_back(vector<string>());
      for (const auto& p: m) {
        if (p.first.size() == w.size()) {
          int count = 0;
          for (int j = 0; j < w.size(); j++) {
            if (p.first[j] != w[j]) count++;
            if (count > 1) break;
          }
          if (count == 1) {
            g[ p.second ].push_back( w );
            g.back().push_back( p.first );
          }
        }
      }
      m[w] = i++;
    }
    //cout << "\ndebe: " << w << '\n';
    string line;
    //getline(cin , line);

    //cout << g.size() << '\n';
    //for (auto & p : m) {
    //  cout << p.first << ": ";
    //  for (auto x: g[p.second]) cout <<  x << " ";
    //  cout<<'\n';
    //}

    while ( getline(cin, line) ) {
      if (line.empty()) break;
      istringstream stm(line);
      stm >> dum >> w;
      //cout << dum << "-" << w << ' ';
      //cout << "." << dum << ".";
      //if (dum.size() == 0) break;
      //cin >> w;
      vector<int> d(g.size(), INF);
      queue<string> q; q.push(dum);
      d[m[dum]] = 0;
      while (! q.empty()) {
        string u = q.front(); q.pop();
        if (u.compare(w) == 0) {
          break;
        }
        for (auto &v:g[m[u]]){
          if (d[m[v]] != INF) continue;
          d[m[v]] = d[m[u]] +1;;
          q.push(v);
        }
      }
      cout << dum << " " << w << " " << d[m[w]] << '\n';
    }
    if ( n )
      cout << '\n';
  }
  return 0;
}


