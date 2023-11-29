// juez62.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool esValida(vector<int>& precipitacion, vector<int>& sol, int& k, vector<int>& abrigos, vector<int>& usos, int& i) {
	bool valid = true;
	if (k > 0) {
		if (sol[k] == sol[k - 1]) {
			valid = false;
		}
	}
	if ( abrigos [i] < precipitacion[k]) {
		valid = false;
	}
	if (usos[i] > (2 + (k / 3))) {
		valid = false;
	}
	return valid;
}

int VA(vector<int>& precipitacion, vector<int>& abrigos, int k, vector<int>& sol, vector<int>& usos) {
	int numSoluciones = 0;
	for (int i = 0; i < abrigos.size(); i = i + 1) {
		sol[k] = i;
		usos[i] += 1;
		if (esValida(precipitacion, sol, k, abrigos, usos, i)) {
			
			if (k == precipitacion.size() - 1) {
				if (sol[0] != sol[k]) {
					/*
					for (int i = 0; i < sol.size(); i = i + 1) {
						cout << sol[i];
					}
					cout << "\n";
					*/
					numSoluciones += 1;
				}
			}
			else {
				numSoluciones += VA(precipitacion, abrigos, k + 1, sol, usos);
			}
		}
		usos[i] -= 1;
	}
	return numSoluciones;
}

bool resuelveCaso() {
	int n;
	int a;
	cin >> n >> a;
	if (n == 0 && a == 0) {
		return false;
	}
	else {
		vector<int> precipitacion(n);
		vector<int> abrigos(a);
		for (int i = 0; i < n; i = i + 1) {
			cin >> precipitacion[i];
		}
		for (int i = 0; i < a; i = i + 1) {
			cin >> abrigos[i];
		}
		vector<int> sol(n);
		vector<int> usos(a, 0);
		int answer = VA(precipitacion, abrigos, 0, sol, usos);
		if (answer != 0) {
			std::cout << answer << "\n";
		}
		else {
			cout << "Lo puedes comprar\n";
		}
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
