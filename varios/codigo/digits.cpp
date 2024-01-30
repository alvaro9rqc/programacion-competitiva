#include <bits/stdc++.h>

using namespace std;


// funcion matematica f(x) = x + 2
// x es la entrada de tu function
// x + 2 es la salida de tu function

// una funcion nos permite recibir parametros, con los cuales realizamos operaciones y podemos retornar un resultado

// [tipo de variable a retornar] [noombre de la function] ( type1 nombre_param1, type2 nombre_param2, .....) {
    // codigo a ejecutar
    // si el tipo de variable a retornar de la function no es void , es obligatorio retornar una varibale con el mismo tipo
    // return value; // value debe tener el mismo tipo del valor de la funcion a retornar
    // en otro caso (si es void)
    // no se retorna nada y por lo tanto no usar return en ningun lugar
// }

// int suma(int x, int y) {
//     int result = x + y;
//     return result;
// }
// para la funcion suma, 
// [tipo de variable a retornar de la funcion] = int
// parametros
    // int x
    // int y
// return vaue // value debe ser del tipo `int`


int getDigits(int x) { // x = 123
    int digits = 0; 
    if (x == 0) {
        return 1;
    }
    while(x > 0) { // x = 123 , 12, 1, 0
        x = x / 10; // x = 123 / 10 = 12 / 10 = 1 / 10 = 0
        digits++; // digits = 1 / 2 / 3
    }
    return digits; // 3
}

int main() {

    // int x = 5, y = 6;
    // cout << "x + y = "<< x + y << endl;
    // cout << "suma(x, y) = "<< suma(x, y) << endl;
    // cout << "suma(3, 2) = "<< suma(3, 2) << endl;

    // x0 = 42
    // x1 = number de digitos de x0 (42) = 2
    // x2 = number de digitos de x1 (2) = 1
    // x3 = number de digitos de x2 (1) = 1
    // answer = 3

    // x1 <= 10^6
    // x2 <= 7
    // x3 == 1
    // x4 == 1

    string s;
    while (cin >> s) {
        if (s == "END") {
            break;
        }
        string x0 = s;
        // x0 = s (34543543213213)
        int x1 = s.size(); // s.size() retorna la cantidad de digitos de `x0` que se lee y guarda en el string `s`
        string x1String = to_string(x1);
        int x2 = getDigits(x1);
        int x3 = getDigits(x2);
        int x4 = getDigits(x3);
        // cout << "x0 = " << x0 << endl;
        // cout << "x1 = " << x1 << " x1String = "<< x1String << endl;
        // cout << "x2 = " << x2 << endl;
        // cout << "x3 = " << x3 << endl;
        // cout << "x4 = " << x4 << endl;

        if (x1String == x0) {
            cout << 1 << endl;
        } else if(x2 == x1) {
            cout << 2 << endl;
        } else if (x3 == x2) {
            cout << 3 << endl;
        } else if (x4 == x3) {
            cout << 4 << endl;
        } else {
            assert("ERROR!");
        }
    }

    return 0;
}