#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <set>
#include <algorithm>
#include <random>

using namespace std;

struct Interval {
    int l, r;
    bool operator<(const Interval& other) const {
        if (r != other.r) return r < other.r;
        return l < other.l;
    }
};

// Solución óptima O(J log J + J log S) para el juez
long long solve_case(int j, int s, vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end());
    multiset<int> servers;
    for (int i = 0; i < s; ++i) {
        servers.insert(0);
    }
    
    long long ans = 0;
    for (const auto& iv : intervals) {
        // Buscar el santuario que se liberó más tarde pero antes o igual al inicio del ritual
        auto it = servers.upper_bound(iv.l);
        if (it != servers.begin()) {
            --it; // Este es el santuario óptimo
            servers.erase(it);
            servers.insert(iv.r);
            ans++;
        }
    }
    return ans;
}

mt19937 rng(1337);
int random_range(int min, int max) {
    uniform_int_distribution<int> dist(min, max);
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

bool run_test(const string& exe_path, int test_id) {
    int J, S;
    vector<Interval> intervals;

    // Casos manuales / Borde
    if (test_id == 0) { 
        // Caso 1: Intervalos anidados y S=1
        J = 5; S = 1;
        intervals = {{1, 100}, {2, 10}, {3, 5}, {11, 20}, {21, 30}};
    } else if (test_id == 1) { 
        // Caso 2: Límites exactos (r_i == l_{i+1})
        J = 4; S = 2;
        intervals = {{1, 5}, {5, 10}, {5, 15}, {10, 20}};
    } else if (test_id == 2) { 
        // Caso 3: Más santuarios que jarjachas
        J = 3; S = 10;
        intervals = {{1, 2}, {1, 2}, {1, 2}};
    } else if (test_id == 3) { 
        // Caso 4: Intervalos idénticos, menos santuarios
        J = 5; S = 2;
        intervals = {{10, 20}, {10, 20}, {10, 20}, {10, 20}, {10, 20}};
    } else if (test_id == 4) { 
        // Caso 5: Fuerza la estrategia de "latest available server"
        J = 4; S = 2;
        intervals = {{1, 5}, {2, 10}, {11, 15}, {6, 12}};
    } else if (test_id == 5) { 
        // Caso 6: Un intervalo gigante ocultando a los óptimos pequeños
        J = 3; S = 1;
        intervals = {{1, 1000000000}, {2, 3}, {4, 5}};
    } 
    // Casos aleatorios y estrés
    else {
        if (test_id < 15) {
            J = random_range(1, 1000);
            S = random_range(1, 500);
        } else {
            J = random_range(150000, 200000); // Límite máximo
            S = random_range(1, 200000);
        }

        intervals.resize(J);
        for (int i = 0; i < J; ++i) {
            int l = random_range(1, 999999998);
            int r = random_range(l + 1, 1000000000);
            intervals[i] = {l, r};
        }
    }

    // Escribir input
    ofstream in("test.in");
    in << J << " " << S << "\n";
    for (int i = 0; i < J; ++i) {
        in << intervals[i].l << " " << intervals[i].r << "\n";
    }
    in.close();

    long long expected = solve_case(J, S, intervals);

    // Formatear comando y prevenir error de rutas
    string cmd = exe_path + " < test.in > test.out";
    if (exe_path[0] != '/' && exe_path.find("./") != 0 && exe_path.find("../") != 0) {
        cmd = "./" + exe_path + " < test.in > test.out";
    }
    
    int ret = system(cmd.c_str());
    if (ret != 0) {
        cout << "\n\nError: RTE o TLE en el test " << test_id + 1 << ".\n";
        return false;
    }

    // Verificar
    ifstream out("test.out");
    long long user_ans;
    if (!(out >> user_ans)) {
        cout << "\n\nError: Falta salida en el test " << test_id + 1 << ".\n";
        return false;
    }

    if (user_ans != expected) {
        cout << "\n\nError: Respuesta incorrecta (WA) en el test " << test_id + 1 << ".\n";
        cout << "Esperado: " << expected << " | Obtenido: " << user_ans << "\n";
        return false;
    }
    
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <tu_ejecutable>\n";
        return 1;
    }

    string exe_path = argv[1];
    int total_tests = 30;

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
