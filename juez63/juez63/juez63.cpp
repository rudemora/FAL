// juez63.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void mostrar(vector<int>& sol) {
	for (int i = 0; i < sol.size(); i = i + 1) {
		cout << sol[i] << " ";
	}
}

bool esValida(vector<int>& sol, int k, vector<string>& tipos) {
	bool valid = true;
	if (k % 2 == 1) {
		if (sol[k] <= sol[k - 1]) {
			valid = false;
		}
		if (tipos[sol[k]] == tipos[sol[k-1]]) {
			valid = false;
		}
	}
	return valid;
}

int VA(vector<string>& tipos, int& n, int k, vector<int>& sol) {
	int numSol = 0;
	for (int i = 0; i < tipos.size(); i = i + 1) {
		sol[k] = i;
		if (esValida(sol, k, tipos)) {
			if (k == (2*n -1)) {
				mostrar(sol);
				cout << "\n";
				numSol += 1;
			}
			else {
				numSol += VA(tipos, n, k + 1, sol);
			}
		}
	}
	return numSol;
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
		vector<string> tipos(m);
		vector<int> sol(n*2);
		for (int i = 0; i < m; i = i + 1) {
			cin >> tipos[i];
		}
		int exists = VA(tipos, n, 0, sol);
		if (!exists) {
			cout << "SIN SOLUCION\n";
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
