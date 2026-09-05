#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;

// --- ESTRUCTURAS BÁSICAS ---
struct Query {
    int L, R, K;
};

struct Node {
    int count;
    int left, right;
    Node(int cnt = 0, int l = 0, int r = 0) : count(cnt), left(l), right(r) {}
};

// --- ORÁCULO 1: FUERZA BRUTA (O(C * B log B)) ---
vector<int> solve_brute(int b, int c, const vector<int>& a, const vector<Query>& queries) {
    vector<int> ans;
    ans.reserve(c);
    for (const auto& q : queries) {
        vector<int> sub(a.begin() + (q.L - 1), a.begin() + q.R);
        sort(sub.begin(), sub.end());
        ans.push_back(sub[q.K - 1]);
    }
    return ans;
}

// --- ORÁCULO 2: SEGMENT TREE PERSISTENTE (O((B + C) log B)) ---
const int MAXB = 100005;
Node tree[MAXB * 22]; 
int root[MAXB];
int node_cnt = 0;

int insert_tree(int prev_root, int l, int r, int val) {
    int curr = ++node_cnt;
    tree[curr] = tree[prev_root];
    tree[curr].count++;

    if (l == r) return curr;

    int mid = l + (r - l) / 2;
    if (val <= mid) {
        tree[curr].left = insert_tree(tree[prev_root].left, l, mid, val);
    } else {
        tree[curr].right = insert_tree(tree[prev_root].right, mid + 1, r, val);
    }
    return curr;
}

int query_tree(int left_root, int right_root, int l, int r, int k) {
    if (l == r) return l;

    int count_in_left = tree[tree[right_root].left].count - tree[tree[left_root].left].count;
    int mid = l + (r - l) / 2;

    if (count_in_left >= k) {
        return query_tree(tree[left_root].left, tree[right_root].left, l, mid, k);
    } else {
        return query_tree(tree[left_root].right, tree[right_root].right, mid + 1, r, k - count_in_left);
    }
}

vector<int> solve_optimal(int b, int c, const vector<int>& a, const vector<Query>& queries) {
    node_cnt = 0; // Reiniciar estado global para múltiples casos de prueba
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());
    int m = sorted_a.size();

    root[0] = 0;
    tree[0] = Node(0, 0, 0);

    for (int i = 0; i < b; i++) {
        int pos = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin() + 1;
        root[i + 1] = insert_tree(root[i], 1, m, pos);
    }

    vector<int> ans;
    ans.reserve(c);
    for (const auto& q : queries) {
        int ans_idx = query_tree(root[q.L - 1], root[q.R], 1, m, q.K);
        ans.push_back(sorted_a[ans_idx - 1]);
    }
    return ans;
}

// --- INFRAESTRUCTURA DE TESTING ---
mt19937 rng(1337);
int random_range(int min_val, int max_val) {
    uniform_int_distribution<int> dist(min_val, max_val);
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
    int B, C;
    vector<int> a;
    vector<Query> queries;
    bool use_brute_force = false;

    // 1. GENERACIÓN DE CASOS
    if (test_id == 0) {
        // Caso 1: Mínimo absoluto (Límite inferior B=1, C=1)
        B = 1; C = 1;
        a = {42};
        queries = {{1, 1, 1}};
        use_brute_force = true;
    } else if (test_id == 1) {
        // Caso 2: Elementos idénticos y límite superior
        B = 4; C = 3;
        a = {1000000000, 1000000000, 1000000000, 1000000000};
        queries = {{1, 4, 1}, {1, 4, 4}, {2, 3, 2}};
        use_brute_force = true;
    } else if (test_id == 2) {
        // Caso 3: Arreglo estrictamente decreciente
        B = 5; C = 4;
        a = {50, 40, 30, 20, 10};
        queries = {{1, 5, 1}, {1, 5, 5}, {2, 4, 1}, {2, 4, 3}};
        use_brute_force = true;
    } else if (test_id == 3) {
        // Caso 4: Duplicados alternados
        B = 6; C = 5;
        a = {5, 1, 5, 3, 1, 2};
        queries = {{1, 1, 1}, {5, 5, 1}, {1, 6, 1}, {1, 6, 3}, {1, 6, 6}};
        use_brute_force = true;
    } else if (test_id < 15) {
        // Casos aleatorios medianos (validados con fuerza bruta)
        B = random_range(100, 1000);
        C = random_range(100, 1000);
        a.resize(B);
        for (int i = 0; i < B; ++i) a[i] = random_range(1, 1000000);
        
        queries.resize(C);
        for (int i = 0; i < C; ++i) {
            int L = random_range(1, B);
            int R = random_range(1, B);
            if (L > R) swap(L, R);
            int K = random_range(1, R - L + 1);
            queries[i] = {L, R, K};
        }
        use_brute_force = true;
    } else {
        // Casos aleatorios de estrés (validados con la solución óptima)
        B = 100000;
        C = 100000;
        a.resize(B);
        for (int i = 0; i < B; ++i) a[i] = random_range(1, 1000000000);
        
        queries.resize(C);
        for (int i = 0; i < C; ++i) {
            int L = random_range(1, B);
            int R = random_range(1, B);
            if (L > R) swap(L, R);
            int K = random_range(1, R - L + 1);
            queries[i] = {L, R, K};
        }
    }

    // 2. ESCRIBIR ENTRADA AL ARCHIVO
    ofstream in("test.in");
    in << B << " " << C << "\n";
    for (int i = 0; i < B; ++i) {
        in << a[i] << (i == B - 1 ? "" : " ");
    }
    in << "\n";
    for (int i = 0; i < C; ++i) {
        in << queries[i].L << " " << queries[i].R << " " << queries[i].K << "\n";
    }
    in.close();

    // 3. OBTENER RESPUESTAS ESPERADAS
    vector<int> expected;
    if (use_brute_force) {
        expected = solve_brute(B, C, a, queries);
    } else {
        expected = solve_optimal(B, C, a, queries);
    }

    // 4. EJECUTAR EL PROGRAMA DEL USUARIO
    string cmd = exe_path + " < test.in > test.out";
    if (exe_path[0] != '/' && exe_path.find("./") != 0 && exe_path.find("../") != 0) {
        cmd = "./" + exe_path + " < test.in > test.out";
    }
    
    int ret = system(cmd.c_str());
    if (ret != 0) {
        cout << "\n\nError: Ejecución fallida (RTE/TLE) en el test " << test_id + 1 << ".\n";
        return false;
    }

    // 5. VERIFICAR SALIDA
    ifstream out("test.out");
    for (int i = 0; i < C; ++i) {
        int user_ans;
        if (!(out >> user_ans)) {
            cout << "\n\nError: Faltan salidas en el test " << test_id + 1 << " (Línea " << i + 1 << ").\n";
            return false;
        }
        if (user_ans != expected[i]) {
            cout << "\n\nError: Respuesta incorrecta (WA) en el test " << test_id + 1 << ".\n";
            cout << "Consulta: L=" << queries[i].L << ", R=" << queries[i].R << ", K=" << queries[i].K << "\n";
            cout << "Esperado: " << expected[i] << " | Obtenido: " << user_ans << "\n";
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <ejecutable_a_evaluar>\n";
        return 1;
    }

    string exe_path = argv[1];
    int total_tests = 30; // 5 manuales + 10 medianos + 15 de estres

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
