#include <bits/stdc++.h>

using namespace std;

int SUM;
// pos -> [0, N-1]
void rec(int pos, int currSum, int N, const vector<int>& A, vector<int> sub) {
	// condicion de parada o termino
	// Hemos procesado todos los elementos del array A
	if (pos == N) {
		if (currSum == SUM) {
			// encontre un subconjunto cuya suma de elementos es igual a SUM
			// cout << "Found\n";	
	
		}
			cout << "SUbconjunto generado: ";
			for (int elem : sub) {
					cout << elem << " ";
			}
			cout << "\n";
		return;
	}

	// primera posibilidad: Tomo A[pos]
	vector<int> newSub = sub;
	newSub.push_back(A[pos]);
	rec(pos+1, currSum + A[pos], N, A, newSub);
	// segunda posibilidad: Ignoro A[pos]
	rec(pos+1, currSum         , N, A, sub);
}

int main (){
	ios_base::sync_with_stdio(false);

	SUM = 40;
	int N = 3;
	vector<int> A = {25, 5, 15};
	vector<int> sub;
	rec(0, 0, N, A, sub);
	

	return 0;	
}