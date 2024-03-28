#include <bits/stdc++.h> 
using namespace std;
int main () {
  int t; scanf("%d", &t);
  while (t--) {
    int n, k; scanf("%d %d", &n, &k);
    priority_queue<tuple<int, int, string, int>> pq;
    while (n--) {
      int fre;
      string name;
      cin >> name >> fre;
      pq.push({-fre, n, name, -fre});
    }
    while (k--) {
      cout << - get<0>(pq.top()) << " " << get<2>(pq.top()) << '\n';
      int time = get<0>(pq.top());
      tuple<int, int, string, int> t;
      t = {get<0>(pq.top()) + get<3>(pq.top()), get<1>(pq.top()), get<2>(pq.top()), get<3>(pq.top())};
      pq.pop();
      pq.push(t);
      //cout << "time: " << time << " second: " << get<0>(pq.top()) << '\n';
      while (time == get<0>(pq.top()) && k) {
        //cout << "entró\n";
        cout << - get<0>(pq.top()) << " " << get<2>(pq.top()) << '\n';
        t = {get<0>(pq.top()) + get<3>(pq.top()), get<1>(pq.top()), get<2>(pq.top()), get<3>(pq.top())};
        pq.pop();
        pq.push(t);
        k--;
      }
    }
    //cout << "time: " << -get<0>(pq.top()) << '\n';
    //cout << "name: " << get<2>(pq.top()) << '\n';
    //cout << "prior:" << get<1>(pq.top()) << '\n';
  } 
  return 0;
}

