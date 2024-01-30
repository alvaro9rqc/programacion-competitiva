#include <bits/stdc++.h>

using namespace std;

void adjMatrixRepresentation(int nodes, int edges) {
    // 1. Adjacent Matrix
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));
    // add edge 0
    adjMatrix[0][2] = 1;
    adjMatrix[2][0] = 1;
    // add edge 1
    adjMatrix[2][3] = 1;
    adjMatrix[3][2] = 1;
    // add edge 2
    adjMatrix[1][3] = 1;
    adjMatrix[3][1] = 1;
    // add edge 3
    adjMatrix[1][2] = 1;
    adjMatrix[2][1] = 1;
    cout << "Adjacent Matrix\n";
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void adjListRepresentation(int nodes, int edges) {
    // 2. Adjacent List
    vector<vector<int>> adjList(nodes, vector<int>());
    // 0: {}
    // 1: {}
    // 2: {}
    // 3: {}
    // add edge 0
    adjList[0].push_back(2);
    adjList[2].push_back(0);
    // add edge 1
    adjList[2].push_back(3);
    adjList[3].push_back(2);
    // add edge 2
    adjList[1].push_back(3);
    adjList[3].push_back(1);
    // add edge 3
    adjList[1].push_back(2);
    adjList[2].push_back(1);

    cout << "Adjacent List:\n";
    for (int i = 0; i < nodes; i++) {
        cout << "vecinos del vertice " << i << ": ";
        for(int nei : adjList[i]) {
            cout << nei << " ";
        }
        cout << "\n";
    }   
}

int main() {
    
    // G = {V, E}
    // V = {0, 1, 2, 3}
    // E = { {0, 2}, {2, 3}, {1, 3}, {1, 2}}
    int nodes = 4;
    int edges = 4;
    adjMatrixRepresentation(nodes, edges);
    adjListRepresentation(nodes, edges);
    // 3. Edge List
    vector<pair<int,int>> graphEdges;
    graphEdges.push_back({0, 2});
    graphEdges.push_back({2, 3});
    graphEdges.push_back({1, 3});
    graphEdges.push_back({1, 2});

    cout << "Edge List:\n";
    for(auto e : graphEdges) {
        cout << e.first << " " << e.second << "\n";
    }

	
	return 0;
}