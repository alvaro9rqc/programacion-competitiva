#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> vis;
int currentComponent;

void dfs(int u) {
    vis[u] = true;
    currentComponent++;
    for(int v : graph[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}

int main(int, char **)
{
    int n;
    cin >> n;
    graph.assign(n, vector<int>());
    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (x == 0 || y == 0) {
            continue;
        }
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vis.assign(n, false);
    int maxComponent = 0;
    for(int i = 1; i < n; i++) { 
        if(!vis[i]) {
            currentComponent = 0;    
            dfs(i);
            // cout << "currentComponent = " << currentComponent << "\n";
            maxComponent = max(maxComponent, currentComponent);
        }
    }
    cout << n - maxComponent << "\n";

    return 0;
}