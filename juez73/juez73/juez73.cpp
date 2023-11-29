// juez73.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void mostrar(vector<int>& sol) {
	for (int i = 0; i < sol.size(); i = i + 1) {
		cout << sol[i] << " ";
	}
	cout << "\n";
}

bool esValida(vector<vector<int>>& v, vector<int>& sol,vector<bool>& marcas, int i, int k) {
	if (marcas[i]) {
		return false;
	}
	int j = k - 2;
	while (j < k) {
		if (j >= 0) {
			if (v[sol[k]][sol[j]] == 1) {
				return false;
			}
		}
		j += 1;
	}
	return true;
}



void resolver(vector<vector<int>>& v, vector<int>& satis, int& satisActual, int& satisMax, vector<int>& sol, vector<int>& solMejor, bool& exito, int k, vector<bool>& marcas, vector<int>& acum) {
	for (int i = 0; i < v.size(); i++) {
		sol[k] = i;
		if (esValida(v, sol, marcas, i, k)) {
			marcas[i] = true;
			satisActual += satis[i];
			if (k == sol.size() - 1) {
				if (satisActual > satisMax) {
					satisMax = satisActual;
					solMejor = sol;
					exito = true;
				}
			}
			else if (satisActual + acum[k] > satisMax) {
				resolver(v, satis, satisActual, satisMax, sol, solMejor, exito, k + 1, marcas, acum);
			}
			marcas[i] = false;
			satisActual -= satis[i];
		}
		
		
	}
}

void resuelveCaso() {
	int n;
	cin >> n;
	int x;
	cin >> x;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	vector<int> satis(n);
	for (int i = 0; i < n; i++) {
		cin >> satis[i];
	}
	bool exito = false;
	int satisActual = 0;
	int satisMax = 0;
	vector<int> sol(x);
	vector<int> solMejor(x);
	vector<bool> marcas(n, false);
	vector<int> acum(n);
	acum[n - 1] = satis[n - 1];
	for (int i = n - 2; i >= 0; i = i - 1) {
		acum[i] += acum[i + 1] +  satis[i];
	}
	resolver(v, satis, satisActual, satisMax, sol, solMejor, exito, 0, marcas, acum);
	if (exito) {
		cout << satisMax << " ";
		mostrar(solMejor);
	}
	else {
		cout << "IMPOSIBLE\n";
	}


}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		resuelveCaso();
	}
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	system("PAUSE");
#endif
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
