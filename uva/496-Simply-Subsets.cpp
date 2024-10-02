#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  string A, B;
  while (getline(cin, A)) {
    getline(cin, B);
    stringstream la(A);
    stringstream lb(B);
    unordered_set<int> a;
    unordered_set<int> b;
    int d;
    while (la >> d) 
      a.insert(d);
    while (lb >> d) 
      b.insert(d);
    char ca = 'A', cb='B';
    if (b.size() > a.size()) 
    {
      swap(a, b);
      swap(ca, cb);
    }
    bool eq = true, dis = true;
    for(auto& e : b) {
      if (a.find(e) == a.end()) {
        eq = false;
      } else  dis = false;
    }
    if (eq && a.size() == b.size()) cout << ca << " equals " << cb<<'\n';
    else if (eq) {
      cout << cb << " is a proper subset of " << ca<<'\n';
    }
    else if (dis) cout << "A and B are disjoint"<<'\n';
    else cout << "I'm confused!\n";
  }
  return 0;
}


