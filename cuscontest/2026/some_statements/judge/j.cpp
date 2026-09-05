#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

// Solución óptima O(n) interna para generar el output esperado
long long solve_case(int n, int k, const vector<int>& a) {
    vector<long long> count(k, 0);
    count[0] = 1;
    long long current_sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        current_sum = (current_sum + a[i]) % k;
        ans += count[current_sum];
        count[current_sum]++;
    }
    return ans;
}

int random_range(int min, int max) {
    return min + rand() % (max - min + 1);
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
    int T;
    // Distribución de carga para mantener el tiempo bajo los 20 segundos
    if (test_id < 10) T = 20;        // Casos pequeños / borde
    else if (test_id < 20) T = 5;    // Casos medianos
    else T = 2;                      // Casos grandes (límite de memoria/tiempo)

    ofstream in("test.in");
    in << T << "\n";

    vector<long long> expected;

    for (int t = 0; t < T; ++t) {
        int n, k;
        if (test_id < 5) {
            n = random_range(1, 100);
            k = random_range(1, 5); // K pequeño
        } else if (test_id < 10) {
            n = random_range(1, 1000);
            k = 1; // Borde: todo es divisible por 1
        } else if (test_id < 20) {
            n = random_range(1000, 50000);
            k = random_range(1, 100);
        } else {
            // Límite máximo: n = 10^6
            n = random_range(800000, 1000000);
            k = random_range(1, 100);
        }

        in << n << " " << k << "\n";
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            if (test_id % 3 == 0) a[i] = random_range(1, 10); 
            else a[i] = random_range(1, 10000);
            in << a[i] << (i == n - 1 ? "" : " ");
        }
        in << "\n";
        expected.push_back(solve_case(n, k, a));
    }
    in.close();

    // Ejecución
    string cmd = "./" + exe_path + " < test.in > test.out";
    if (exe_path.find("./") == 0) {
        cmd = exe_path + " < test.in > test.out";
    }
    
    int ret = system(cmd.c_str());
    if (ret != 0) {
        cout << "\n\nError: RTE o TLE en el test " << test_id + 1 << ".\n";
        return false;
    }

    // Verificación
    ifstream out("test.out");
    for (int t = 0; t < T; ++t) {
        long long user_ans;
        if (!(out >> user_ans)) {
            cout << "\n\nError: Falta salida en el test " << test_id + 1 << ", caso " << t + 1 << ".\n";
            return false;
        }
        if (user_ans != expected[t]) {
            cout << "\n\nError: Respuesta incorrecta (WA) en el test " << test_id + 1 << ", caso " << t + 1 << ".\n";
            cout << "Esperado: " << expected[t] << " | Obtenido: " << user_ans << "\n";
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <tu_ejecutable>\n";
        cout << "Ejemplo: " << argv[0] << " ans.out\n";
        return 1;
    }

    srand(time(NULL));
    string exe_path = argv[1];
    int total_tests = 30; // 30 archivos de prueba en total

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

    // Limpieza de archivos residuales
    system("rm -f test.in test.out");
    return 0;
}
