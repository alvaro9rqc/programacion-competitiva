#include <bits/stdc++.h>

using namespace std;
	
int main (){
	// para acelrar la lectura y salida del cin y cout
	ios_base::sync_with_stdio(false);
	// casos de orueba
	int T;
	cin >> T;
	for(int tc = 0; tc < T; tc++) {
		// numero de instrucciones
		int n;
		cin >> n;
		vector<string> instructions(n);
		// LEFT
		// RIGHT
		// SAME AS i
		int posRobot = 0;
		for (int i = 0; i < n; i++) {
			string ins;
			cin >> ins;
			if (ins == "SAME") {
				string as;
				int pos;
				cin >> as >> pos;
				instructions[i] = instructions[pos-1];
			} else {
				instructions[i] = ins;
			}
			if (instructions[i] == "LEFT") {
				posRobot--;
			} else {
				posRobot++;
			}
		}
		cout << posRobot << endl;
	}

	return 0;
	
}