#include <bits/stdc++.h>

using namespace std;

struct Team {
	string name;
	int points;
	int goals;
};

// struct Colegio {
// 	string nombre;
// 	int cantidadAlumnos;
// 	//
// };

class Alumno {
	string nombre;
	int codigo;
	int grado;
	string seccion;
	int dni;

	int get_age() {

	} 
	string hobbies() {
		return "dance";
	}
};

class Colegio {
	string nombre;
	int cantidadAlumnos;
	vector<Alumno> alumnos;

	void trasladarAlumno();

	bool matricularAlumno(int codigoAlumno, string nombre) {
		// 
	}
};

// ordena los equipos por la mayor cantidad de puntos obtenidos y si hay un empate
// ordena por la mayor cantidad de goles
int cmpTeam(const Team& team1, const Team& team2) {
	if (team1.points != team2.points) {
		return team1.points > team2.points;
	}
	return team1.goals < team2.goals; 
}

int cmp(int a, int b) {
	return a > b;
}

int main (){
	// para acelrar la lectura y salida del cin y cout
	ios_base::sync_with_stdio(false);

	Colegio coar = {.nombre="Colegio de alto Rendimiento", .cantidadAlumnos = 1567};

	vector<Team> teams;
	Team chelsea = {.name="chelsea", .points=19, .goals=15};
	Team barcelona = {.name="barcelona", .points=19, .goals=20};
	Team dortmund = {.name="dortmund", .points=10, .goals=2};
	teams.push_back(chelsea);
	teams.push_back(barcelona);
	teams.push_back(dortmund);
	sort(teams.begin(), teams.end(), cmpTeam);
	for(auto t : teams) { 
		cout << "name = "<< t.name << " points = " << t.points << " goals = " << t.goals << "\n";
	}

	return 0;



	vector<int> nums = {1, 10, -2, 6};
	cout << "vector unsorted:\n";
	for(auto val : nums) {
		cout << val << " ";
	}
	cout << endl;

	sort(nums.begin(), nums.end());
	cout << "vector sorted:\n";
	for(auto val : nums) {
		cout << val << " ";
	}
	cout << endl;

	sort(nums.rbegin(), nums.rend());
	cout << "vector sorted in reverse order:\n";
	for(auto val : nums) {
		cout << val << " ";
	}
	cout << endl;

	sort(nums.begin(), nums.end(), cmp);



	return 0;	
}