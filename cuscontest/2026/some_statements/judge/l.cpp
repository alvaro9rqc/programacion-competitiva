#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <algorithm>
#include <random>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

struct DSU {
    vector<int> parent;
    int components;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
        components = n;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
        }
    }
};

long long solve_optimal(int N, int M, long long K, const vector<pair<int, int>>& edges) {
    long long total_ways = 0;
    int max_mask = 1 << M;
    for (int mask = 0; mask < max_mask; mask++) {
        DSU dsu(N);
        int edges_used = 0;
        for (int i = 0; i < M; i++) {
            if ((mask >> i) & 1) {
                edges_used++;
                dsu.unite(edges[i].first, edges[i].second);
            }
        }
        long long current_ways = power(K, dsu.components);
        if (edges_used % 2 == 0) {
            total_ways = (total_ways + current_ways) % MOD;
        } else {
            total_ways = (total_ways - current_ways + MOD) % MOD;
        }
    }
    return total_ways;
}

mt19937_64 rng(1337);

int random_range(int min_val, int max_val) {
    uniform_int_distribution<int> dist(min_val, max_val);
    return dist(rng);
}

long long random_range_ll(long long min_val, long long max_val) {
    uniform_int_distribution<long long> dist(min_val, max_val);
    return dist(rng);
}

void show_progress(int current, int total) {
    float progress = (float)current / total;
    int barWidth = 50;
    cout << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "=";
        else if (i == pos) cout << ">";
        else cout << " ";
    }
    cout << "] " << int(progress * 100.0) << " %\r";
    cout.flush();
}

vector<pair<int, int>> generate_random_edges(int N, int M) {
    set<pair<int, int>> unique_edges;
    while (unique_edges.size() < M) {
        int u = random_range(1, N);
        int v = random_range(1, N);
        if (u == v) continue;
        if (u > v) swap(u, v);
        unique_edges.insert({u, v});
    }
    return vector<pair<int, int>>(unique_edges.begin(), unique_edges.end());
}

bool run_test(const string& exe_path, int test_id) {
    int N, M;
    long long K;
    vector<pair<int, int>> edges;

    if (test_id == 0) {
        N = 1; M = 0; K = 1; 
    } else if (test_id == 1) {
        N = 2; M = 1; K = 1; edges = {{1, 2}}; 
    } else if (test_id == 2) {
        N = 3; M = 3; K = 2; edges = {{1, 2}, {2, 3}, {3, 1}}; 
    } else if (test_id == 3) {
        N = 5; M = 2; K = 3; edges = {{1, 2}, {3, 4}}; 
    } else if (test_id == 4) {
        N = 15; M = 14; K = 1000000000LL; 
        for(int i = 2; i <= 15; i++) edges.push_back({1, i});
    } else if (test_id == 5) {
        N = 1; M = 0; K = 1000000000LL; 
    } else if (test_id == 6) {
        N = 4; M = 4; K = 2; edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}}; 
    } else if (test_id == 7) {
        N = 7; M = 20; K = 10; edges = generate_random_edges(N, M); 
    } else if (test_id == 8) {
        N = 15; M = 20; K = 1000000000LL;
        int count = 0;
        for (int i = 1; i <= 7 && count < 20; i++) {
            for (int j = i + 1; j <= 7 && count < 20; j++) {
                edges.push_back({i, j});
                count++;
            }
        }
    } else if (test_id == 9) {
        N = 15; M = 20; K = 1000000000LL;
        for(int i = 1; i < 15; i++) edges.push_back({i, i+1});
        edges.push_back({1, 15}); edges.push_back({3, 10}); edges.push_back({5, 12});
        edges.push_back({2, 14}); edges.push_back({4, 8}); edges.push_back({7, 13});
    } else if (test_id == 10) {
        N = 15; M = 20; K = 1000000000LL;
        int count = 0;
        for(int i = 1; i <= 4 && count < 20; i++) {
            for(int j = 5; j <= 9 && count < 20; j++) {
                edges.push_back({i, j});
                count++;
            }
        }
    } else if (test_id == 11) {
        N = 15; M = 20; K = 1000000000LL;
        edges = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,1},
                 {8,9},{9,10},{10,11},{11,12},{12,8},
                 {13,14},{14,15},{15,13},
                 {1,4},{2,6},{8,10},{9,12},{1,5}};
    } else if (test_id == 12) {
        N = 15; M = 20; K = 1000000000LL;
        for(int i = 2; i <= 15; i++) edges.push_back({1, i}); 
        edges.push_back({2, 3}); edges.push_back({4, 5}); edges.push_back({6, 7}); 
        edges.push_back({8, 9}); edges.push_back({10, 11}); edges.push_back({12, 13});
    } else if (test_id == 13) {
        N = 15; M = 0; K = 1000000000LL; 
    } else if (test_id == 14) {
        N = 15; M = 10; K = 1000000000LL;
        edges = {{1,2},{2,3},{3,4}, {5,6},{6,7},{7,8},{8,9}, {10,11},{11,12},{12,13}};
    } else {
        N = random_range(1, 15);
        int max_possible_edges = N * (N - 1) / 2;
        M = random_range(0, min(20, max_possible_edges));
        K = random_range_ll(1, 1000000000LL);
        edges = generate_random_edges(N, M);
    }

    ofstream in("test.in");
    in << N << " " << M << " " << K << "\n";
    for (int i = 0; i < M; ++i) {
        in << edges[i].first << " " << edges[i].second << "\n";
    }
    in.close();

    long long expected = solve_optimal(N, M, K, edges);

    string cmd = exe_path + " < test.in > test.out";
    if (exe_path[0] != '/' && exe_path.find("./") != 0 && exe_path.find("../") != 0) {
        cmd = "./" + exe_path + " < test.in > test.out";
    }
    
    int ret = system(cmd.c_str());
    if (ret != 0) {
        cout << "\n\nError de ejecución (RTE/TLE) en el test " << test_id + 1 << ".\n";
        return false;
    }

    ifstream out("test.out");
    long long user_ans;
    if (!(out >> user_ans)) {
        cout << "\n\nFalta salida en el test " << test_id + 1 << ".\n";
        return false;
    }
    if (user_ans != expected) {
        cout << "\n\nRespuesta incorrecta (WA) en el test " << test_id + 1 << ".\n";
        cout << "Input N=" << N << ", M=" << M << ", K=" << K << "\n";
        cout << "Esperado: " << expected << " | Obtenido: " << user_ans << "\n";
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <ejecutable_a_evaluar>\n";
        return 1;
    }

    string exe_path = argv[1];
    int total_tests = 50;

    cout << "Evaluando " << exe_path << "...\n";
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < total_tests; ++i) {
        if (!run_test(exe_path, i)) {
            cout << "Ejecución detenida.\n";
            return 1;
        }
        show_progress(i + 1, total_tests);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "\n\nTodos los casos fueron aceptados (AC).\n";
    cout << "Tiempo total empleado: " << elapsed.count() << " s\n";

    system("rm -f test.in test.out");
    return 0;
}
