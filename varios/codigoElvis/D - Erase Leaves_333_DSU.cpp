#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
    vector<int> parent;

public:
    vector<int> size;
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int f(int u) {
        if (u == parent[u]) {
            return u;
        }
        else {
            return parent[u] = f(parent[u]);
        }
    }
    void unir(int x, int y) {
        int px = f(x);
        int py = f(y);
        if (px != py) {
            parent[px] = py;
            size[py] += size[px];
        }
        // cout << "x = " << x << " y = "<< y << "\n";
    }
};

int main(int, char **) {
    int n;
    cin >> n;
    UnionFind solver(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x == 0 || y == 0) {
            continue;
        }
        solver.unir(x, y);
    }

    int maxComponent = 0;
    for (int i = 1; i < n; i++) {
        int pi = solver.f(i);
        // cout << "padre de i = " << i << " es " << pi << "\n";
        maxComponent = max(maxComponent, solver.size[pi]);
    }
    // cout << "maxComponent = " << maxComponent << "\n";
    cout << n - maxComponent << "\n";

    return 0;
}
