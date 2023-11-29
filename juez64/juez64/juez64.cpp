// juez64.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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

bool esValida(vector<int>& sol, vector<string>& tipos, int k, vector<int>& juguetes, int i, vector<int>& satisActual, int& minimSatis) {
	
	bool valid = true;
	if (juguetes[i] < 0) {
		valid = false;
	}
	if (k % 2 == 1) {
		if (tipos[sol[k]] == tipos[sol[k - 1]]) {
			valid = false;
		}
		if (sol[k] <= sol[k - 1]) {
			valid = false;
		}
		if (satisActual[k/ 2] < minimSatis) {
			valid = false;
		}
	}
	return valid;
}

void VA(vector<int>& juguetes, vector<string>& tipos, vector<vector<int>>& satis, vector<int>& satisActual, vector<int>& sol, vector<int>& solMejor, int k, bool& exito, int& minimSatis) {
	for (int i = 0; i < juguetes.size(); i = i + 1) {
		sol[k] = i;
		satisActual[k / 2] += satis[k / 2][i];
		juguetes[i] -= 1;
		if (esValida(sol, tipos, k, juguetes, i, satisActual, minimSatis)) {
			if (k == sol.size() - 1) {
				exito = true;
				mostrar(sol);
			}
			else {
				VA(juguetes, tipos, satis, satisActual, sol, solMejor, k + 1, exito, minimSatis);
			}
			
		}
		satisActual[k / 2] -= satis[k / 2][i];
		juguetes[i] += 1;
		
	}


}

bool resuelveCaso() {
	int m;
	cin >> m;
	if (!cin) {
		return false;
	}
	else {
		int n;
		cin >> n;
		int minimSatis;
		cin >> minimSatis;
		vector<int> juguetes(m);
		vector<string> tipos(m);
		vector<vector<int>> satis(n, vector<int>(m));
		for (int i = 0; i < m; i++) {
			cin >> juguetes[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> tipos[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> satis[i][j];
			}
		}
		vector<int> sol(n * 2);
		vector<int> solMejor(n * 2);
		bool exito = false;
		vector<int> satisActual(n, 0);
		VA(juguetes, tipos, satis, satisActual, sol, solMejor, 0, exito, minimSatis);
		if (!exito) {
			cout << "SIN SOLUCION";
		}
		cout << "\n";
		return true;
	}
}

int main()
{
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif
	while (resuelveCaso());
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
