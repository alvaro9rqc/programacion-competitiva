#include <bits/stdc++.h>

using namespace std;

int main() {

// 3 -> numero de casos

// 8 = n
// 1 4 2 2 3 5 3 4 -> las alturas de los 8 muros
// high jumps = 1 -> 4, 2 -> 3, 3 -> 5, 3 -> 4 = 4 high jumps 
// low jumps = 4 -> 2, 5->3  = 2 low jumps 

// 1 = n
// 9 -> la altura del muro

// 5 = n
// 1 2 3 4 5 -> las alturas de los 5 muros
// high jumps = 4
// low jumps = 0

// numbers = [1, 2, 3,4]
// indices = [0, 1, 2, 3]
// lenght = 4
// numbers[0] = 1
// numbers[1] = 2
// numbers[2] = 3
// que hago si quiero acceder al numero 4
// por la posicion obtengo su valor `numbers[3]`

// numbers2 = [-10, 45, 1, 8, -7]
// que valor tiene numbers2[4] = -7 ??
// numbers2[1] = 45

// ciclo o bucle
// for (initialization (opcional); condition ; operaciones adicionales [opcional]) {
    // el for se ejecuta mientras la condition sea verdadera
// }
    // for (init; condition; update){
    //     // codigo
    // }
    // Secuencia de ejecucion del for
    // [1] init
    // [2] condition , si es true, continuamos, en otro caso, termina
    // [3] codigo
    // [4] update
    // [5] condition, si es true, continuamos, en otro caso, termina el for
    // [6] codigo
    // [7] update
    // [8] condition, ....
    // .....

    // diferencia entre i++ & ++i
    // de manera general, las condiciones hacen la siguiente pregunta para proceder o no:
    //     si la condicion es diferente de 0 o false, se considero que es true o verdadero y procede
    //     en otro case la condicion es falsa y no se procede
    // if (0) {
    //     cout << "ingreso a esta parte! if(0)\n";
    // }
    // if (2) {
    //     cout << "ingreso a esta parte! if(1)\n";
    // }

    // int i = 0;
    // // tenenos 2 eventos
    //     // 1. Lee el valor i
    //     // 2. incrementa el valor de i en 1 -> i = i + 1 
    // if (i++) { 
    //     cout << "no se ejecuta porque en la condicion el valor de i es 0\n";
    //     cout << i << endl; // i = 1
    // }
    // // i = 1

    // i = 0;
    // // tenemos dos eventos
    //     // 1. incremento del valor de i en 1
    //     // 2. lee el valor de i
    // if (++i) {  // i = 1 antes de este corchete
    //     cout << "se ejecuta este segundo if ya que i = 1 cuando la condicion ocurre\n";
    //     cout << i << endl; // i = 1
    // }
    
    // break, te permite terminar un ciclo (salir del while or for)
    // continue, te permite saltar el codigo posterior a este y saltar a `update` en la estrucutra del for
    // while (condition)
    // for (init; condition; update)
    // return 0;

    int testCases;
    int n;
    cin >> testCases;
    int currCase = 1;
    for(int i = 0; i < testCases; i++) {
        cin >> n;
        vector<int> heights; // [2 , 4, 5, 6] lenght = 4
        // al comienzo el vector esta vacio
        // heights = []
        heights.assign(n, 0);  // heights = [0, 0, 0, 0]
        for(int index = 0; index < n; index++) {
            cin >> heights[index]; // lee un valor desde la entrada standar en la posicion `index` del vector `heights`
        }
        int highJumps = 0;
        int lowJumps = 0;
        for (int index = 0; index + 1 < n; index++) {
            // debo comparar las alturas del muro actual con el siguiente
            // si la posicion actual es `index` que empieza en 0, cual es la siguiente posicion -> (index+1)
            // entonces debo comparar los valores de heights[index] y heights[index+1]
            int alturaActual = heights[index];
            int alturaSiguiente = heights[index+1];
            if (alturaActual < alturaSiguiente) {
                highJumps = highJumps + 1; 
                // highJumps++;
                // highJumps += 1;
            }
            
            if (alturaActual > alturaSiguiente) {
                lowJumps = lowJumps + 1;
                // lowJumps++;
                // lowJumps += 1;
            }
        }
        cout << "Case " << currCase << ": " << highJumps << " " << lowJumps << endl;
        currCase++;
    }


    return 0;
}    


