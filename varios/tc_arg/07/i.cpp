#include <iostream>
#include <vector>
using namespace std;

int popcount(unsigned long long x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<unsigned long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        unsigned long long total_or = 0;
        for (auto x : a) total_or |= x;

        unsigned long long current_or = 0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if ((current_or | a[i]) == (current_or)) {
                // no prende bits nuevos, se puede añadir
                count++;
            } else if ((current_or | a[i]) <= total_or) {
                // prende bits nuevos pero aún no pasamos el total
                current_or |= a[i];
                count++;
            }
            // si current_or == total_or, ya podemos incluir libremente
        }

        // Caso especial: si nunca se pudo agregar nada, valor = 0 - popcount(total_or) → puede ser negativo
        int result = count - popcount(total_or);
        if (result < 0) result = 0;

        cout << result << '\n';
    }

    return 0;
}

