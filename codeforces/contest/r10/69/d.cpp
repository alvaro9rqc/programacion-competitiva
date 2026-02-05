#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

// Definiciones para claridad
const int MAXK = 362; // Un poco más de 361 para seguridad en bordes
// dp[f][s][m]
// Usamos dos tablas: una para el índice actual (i) y otra para el siguiente (i+1)
int dp_curr[2][MAXK][MAXK];
int dp_next[2][MAXK][MAXK];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; 
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vi arr(n); 
        for(auto& i: arr) cin >> i;

        // --- Lógica de compresión del vector d (igual que tu código) ---
        int c = arr.front();
        vector<ii> d = {{arr.front(), 0}};
        for (int i = 1; i < n; i++) {
            c = max(c, arr[i]);
            if (d.back().first < arr[i]) 
                d.emplace_back(arr[i], i);
        }
        int sz_d = (int)d.size();
        
        // Limpiamos las tablas DP (opcional si llenamos todo, pero buena práctica)
        // Solo necesitamos limpiar para el rango que usaremos, pero memset es rápido.
        memset(dp_curr, 0, sizeof(dp_curr));
        memset(dp_next, 0, sizeof(dp_next));

        // --- DP Iterativo (Bottom-Up) ---
        // 1. Iteramos i desde el último elemento hacia atrás
        for (int i = sz_d - 1; i >= 0; --i) {
            
            int diff_idx = (i < sz_d - 1) ? (d[i+1].second - d[i].second) : 0;
            int limit_m = c + 1; // Límite seguro para m

            // 2. Iteramos s y m hacia atrás porque las transiciones aumentan s y m
            for (int s = k; s >= 0; --s) {
                for (int m = limit_m; m >= 0; --m) {
                    
                    int ap = k - s; // Available points / presupuesto restante

                    // 3. Iteramos para f=0 y f=1
                    for (int f = 0; f < 2; ++f) {
                        
                        // Caso Base: Último elemento (equivale a i == sz(d)-1 en recursivo)
                        if (i == sz_d - 1) {
                            int val = 0;
                            if (f)
                                val = max(m, min(d[i].first, ap + m)) * (n - d[i].second);
                            else 
                                val = max(m, min(d[i].first, ap)) * (n - d[i].second);
                            
                            dp_curr[f][s][m] = val;
                        } 
                        // Caso Recursivo
                        else {
                            int ans = 0;
                            
                            // Transición básica: moverse al siguiente índice (i+1) con f=0
                            // Esto usa dp_next
                            ans = diff_idx * m + dp_next[0][s][m];

                            // Transiciones complejas (quedarse en i, aumentar s y m)
                            // Usamos dp_curr porque nos quedamos en el mismo i, 
                            // pero accedemos a s y m mayores (que ya calculamos porque los bucles van hacia atrás)
                            if (f) {
                                if (ap > 0 && m < d[i].first) {
                                    // dp(1, s+1, m+1, i)
                                    // Verificamos límites para no salir del array
                                    if (s + 1 <= k && m + 1 < MAXK)
                                        ans = max(ans, dp_curr[1][s+1][m+1]);
                                }
                            } else {
                                if (ap > m && m < d[i].first) {
                                    // dp(1, s+m+1, m+1, i)
                                    if (s + m + 1 <= k && m + 1 < MAXK)
                                        ans = max(ans, dp_curr[1][s+m+1][m+1]);
                                }
                            }
                            dp_curr[f][s][m] = ans;
                        }
                    }
                }
            }
            
            // Copiamos el estado actual al "siguiente" para la próxima iteración de i
            // (Efectivamente movemos la ventana hacia atrás)
            // memcpy es muy rápido para esto
            memcpy(dp_next, dp_curr, sizeof(dp_curr));
        }

        // El resultado final está en el estado inicial: f=0, s=0, m=0, i=0
        cout << dp_curr[0][0][0] << '\n';
    }
}
