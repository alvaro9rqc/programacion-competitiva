#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <algorithm>
#include <random>
#include <numeric>

using namespace std;

// ==========================================
// ORÁCULO: SOLUCIÓN ÓPTIMA DEL JURADO
// ==========================================
long long contar_imposibles(long long x, long long A, long long B) {
    long long posibles = 0;
    for (long long b = 0; b < A && b * B <= x; ++b) {
        posibles += (x - b * B) / A + 1;
    }
    return x - posibles + 1;
}

long long solve_optimal(long long A, long long B, long long K) {
    long long total_imposibles = (A - 1) * (B - 1) / 2;
    if (K > total_imposibles) {
        return -1;
    }
    long long low = 1;
    long long high = A * B - A - B;
    long long ans = -1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (contar_imposibles(mid, A, B) >= K) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// ==========================================
// UTILIDADES DE GENERACIÓN ALEATORIA
// ==========================================
mt19937_64 rng(1337);

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

// ==========================================
// CONTROL DE EJECUCIÓN DE PRUEBAS
// ==========================================
bool run_test(const string& exe_path, int test_id) {
    long long A, B, K;

    // Primeros 15 casos: Deterministas basados en AVL y PE
    if (test_id == 0) { A = 4; B = 7; K = 5; } // PE2: K normal
    else if (test_id == 1) { A = 4; B = 7; K = 10; } // PE1: K excede límite
    else if (test_id == 2) { A = 3; B = 10; K = 9; } // PE3: K es el máximo exacto
    else if (test_id == 3) { A = 2; B = 3; K = 1; } // AVL1: Mínimos valores
    else if (test_id == 4) { A = 100; B = 101; K = 1; } // AVL2: K=1
    else if (test_id == 5) { A = 99991; B = 100000; K = 4999450000LL; } // AVL3: K máximo válido
    else if (test_id == 6) { A = 99991; B = 100000; K = 4999450001LL; } // AVL4: K apenas inválido
    else if (test_id == 7) { A = 4; B = 7; K = 1000000000000000000LL; } // AVL5: K límite de 64 bits
    else if (test_id == 8) { A = 99999; B = 1000000; K = 49998950000LL; } // AVL6: A y B máximos
    else if (test_id == 9) { A = 99999; B = 100000; K = 4999800001LL; } // B = A+1 (Diferencia mínima)
    else if (test_id == 10) { A = 2; B = 999999; K = 400000; } // Diferencia extrema
    else if (test_id == 11) { A = 65537; B = 65539; K = 1000000000LL; } // Trampa de 32 bits
    else if (test_id == 12) { A = 99991; B = 100000; K = 4500000000LL; } // Desbordamiento intermedio en BS
    else if (test_id == 13) { A = 99989; B = 99991; K = 10000000; } // Primos gemelos
    else if (test_id == 14) { A = 2; B = 999983; K = 499991; } // K es el último impar antes de B
    else {
        // Casos 15 al 99: Generación aleatoria estratificada
        int perfil = test_id % 5;
        if (perfil == 0) { // Pequeños
            A = random_range_ll(2, 1000);
            B = random_range_ll(A + 1, 5000);
        } else if (perfil == 1) { // Diferencia extrema
            A = random_range_ll(2, 15);
            B = random_range_ll(990000, 1000000);
        } else if (perfil == 2) { // Diferencia mínima
            A = random_range_ll(90000, 100000);
            B = A + random_range_ll(1, 3);
        } else if (perfil == 3) { // Aleatorio general
            A = random_range_ll(50000, 100000);
            B = random_range_ll(A + 1, 1000000);
        } else { // Estrés de valores máximos
            A = random_range_ll(99990, 100000);
            B = random_range_ll(999990, 1000000);
        }

        // Asegurar coprimalidad y A < B
        while (std::gcd(A, B) != 1 || A >= B) {
            B++;
        }

        // Asignación probabilística de K
        long long Max_K = (A - 1) * (B - 1) / 2;
        int tipo_k = random_range_ll(1, 100);
        
        if (tipo_k <= 20) K = random_range_ll(1, max(1LL, Max_K - 1));
        else if (tipo_k <= 40) K = random_range_ll(1, 2);
        else if (tipo_k <= 60) K = Max_K;
        else if (tipo_k <= 80) K = random_range_ll(Max_K + 1, Max_K + 100);
        else K = random_range_ll(1000000000000000LL, 1000000000000000000LL);
    }

    // Escribir archivo de entrada
    ofstream in("test.in");
    in << A << " " << B << " " << K << "\n";
    in.close();

    long long expected = solve_optimal(A, B, K);

    string cmd = exe_path + " < test.in > test.out";
    if (exe_path[0] != '/' && exe_path.find("./") != 0 && exe_path.find("../") != 0) {
        cmd = "./" + exe_path + " < test.in > test.out";
    }
    
    int ret = system(cmd.c_str());
    if (ret != 0) {
        cout << "\n\nError de ejecución (RTE/TLE) en el test " << test_id + 1 << ".\n";
        cout << "Input: A=" << A << ", B=" << B << ", K=" << K << "\n";
        return false;
    }

    ifstream out("test.out");
    long long user_ans;
    if (!(out >> user_ans)) {
        cout << "\n\nFalta salida en el test " << test_id + 1 << ".\n";
        cout << "Input: A=" << A << ", B=" << B << ", K=" << K << "\n";
        return false;
    }
    
    if (user_ans != expected) {
        cout << "\n\nRespuesta incorrecta (WA) en el test " << test_id + 1 << ".\n";
        cout << "Input: A=" << A << ", B=" << B << ", K=" << K << "\n";
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
    int total_tests = 100;

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
