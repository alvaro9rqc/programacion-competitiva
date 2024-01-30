#include <bits/stdc++.h>

using namespace std;
	
double price(int k) {
	return pp * (sin(aa * k + bb) + cos(cc * k + dd) + 2);
}

double pp, aa, bb, cc, dd;

int main (){
	// para acelrar la lectura y salida del cin y cout
	ios_base::sync_with_stdio(false);
	int p, a, b, c, d, n;
	
	while(cin >> p >> a >> b >> c >> d >> n) {
	int i = 1, l = 1;
	int u = 1;
	double pico = price(1), valleDespuesDePico, mayorDiferencia = 0;
	pp = p;
	aa = a;
	bb = b;
	cc = c;
	dd = d;
	pico = price(1);
	valleDespuesDePico = price(1);
	i++;
	while (i <= n) {
		double curr = price(i);
		// pico = maxPrefix
		pico = max(pico, curr);
		// mayorDiferencia = ans
		mayorDiferencia = max(mayorDiferencia, pico - curr);
		i++;
	}

	cout << fixed << setprecision(9) << mayorDiferencia << endl;
	}

	return 0;
	
}