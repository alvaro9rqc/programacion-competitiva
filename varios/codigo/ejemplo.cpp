#include <bits/stdc++.h>

using namespace std;

// retorna el valor de ceil(a/b)
int myCeil(int a, int b) { 
	return (a + b - 1) / b;
	// myCeil(7, 2) {
		// a = 7
		// b = 2
		// return (a + b - 1) / b = (7 + 2 - 1) / 2 = 8 / 2 = 4
		// a = 11
		// b = 5
		// return (11 + 5 - 1) / 5 = 15 / 5 = 3
	// }
}

int main() {

	// el numero 2 en c++ es reconocido como entero
	// el numero 2.2 en c++ es reconocido como float o double
	// casteo, conversion de entero a double o float
		// (double)2 es equivalente a 2.0
		// double(2) es  equivalente a 2.0
		// (float)2 es equivalente a 2.0
		// float(2) es  equivalente a 2.0
	// `float` usa 32 bits -> 2^32 posibles valores
	// `double` usa 64 bits -> 2^64 posibles valores
	// `int` usa 32 bits -> 2^32 posibles valores
	// `long long` usa 64 bits -> 2^32 posibles valores -> sus valores van desde [-2^63, 2^63-1]

	// Division redondeando hacia arriba
	// cout << "ceil(5 / (double)4) = "<<ceil(5 / (double)4) << endl; // 1.25 -> 2
	// cout << "ceil(7.0 / 2) = "<< ceil(7.0 / 2) << endl; // 3.5 -> 4

	// // Division redondeando hacia abajo
	// cout << "floor(5.0 / 4) = "<< floor(5.0 / 4) << endl; // 1.25 -> 1
	// cout << "floor(7.0 / 2) = "<< floor(7.0 / 2) << endl; // 3.5 -> 3
	// cout << "5 / 4 = "<< 5 / 4 << endl;
	// cout << "7 / 2 = "<< 7 / 2 << endl;

	int t;
	int rows, colums;
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> rows >> colums;
		// solution
		int minRows = myCeil((rows - 2) , 3);
		int minCols = myCeil((colums- 2) , 3);
		cout << minRows * minCols << endl;
		// min =  [(rows - 2) / 3 ] [ (colums - 2) / 3] las divisiones deber ser hacia arriba
	}

	return 0;
}