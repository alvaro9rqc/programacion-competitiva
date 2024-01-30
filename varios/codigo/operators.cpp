#include <bits/stdc++.h>

using namespace std;

int main() {

    int testCases;
    int a, b;

    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        cin  >> a >> b;
        
        // if (condition) {
        //     // si condition is true ejecutamos esta parte del codigo
        // } else { // se ejecuta en caso la condicion sea falsa
        // }
        if (a > b) {
            cout << ">" << endl;
        } else { // si (a > b) is false, then a <= b
            if (a < b) {
                cout << "<" << endl;
            } else { // si (a < b) is false, then a = b
                cout << "=" << endl;
            }
        }
    }

	return 0;
}