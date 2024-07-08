#include <bits/stdc++.h> 
using namespace std;
int bsf (vector<vector<int>>& graph, int& v, int& w) {
  vector<bool> visited(graph.size(), false);
  queue<int> q;
  int dist = 1;
  q.push(v);
  int t = 1;
  visited[v] = true;
  while (!q.empty() && !(dist > w)) {
    int l = q.size();
    //todos los nodos en el nivel
    for (int i = 0; i < l; i++) {
      //todos lso nodos del nodo actual
      for (int n : graph[q.front()]) {
        if (! visited[n]) {
          q.push(n);
          visited[n] = true;
          t++;
          //printf("%d, %d -" , n, dist);
        }
      }
      q.pop();
    }
    dist++;
  } 
  return t;
}

int main () {
  ios_base::sync_with_stdio(false);
  int t, a, b;
  int counter = 0;
  while (true) {
    cin >> t;
    if (t == 0) break;
    vector< vector<int>> graph;
    unordered_map<int, int>m;
    int top = 0;
    for (int i = 0; i < t; i++) {
      cin >> a >> b; 
      if (m.find(a) == m.end()) {
        m[a] = top;
        top ++;
        graph.push_back(vector<int>());
      }
      if (m.find(b) == m.end()) {
        m[b] = top;
        top ++;
        graph.push_back(vector<int>());
      }
      graph[m[a]].push_back(m[b]);
      graph[m[b]].push_back(m[a]);
    }
    while (true) {
      cin >> a >> b;
      //printf("%d-%d %d\n", a, b, counter+1);
      if (a == 0 && b == 0) break;
      counter++;
      if (m.find(a) == m.end() ) {
        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", counter, (int) m.size()- 0, a, b);
      } else {
        int reach = bsf(graph, m[a], b);
        //printf("%d - %d - %d", reach,(int) m.size(), m[a]);
        //printf("<-%d->", reach);
        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", counter, (int) m.size()- reach, a, b);

      }
    }
  }
  return 0;
}


