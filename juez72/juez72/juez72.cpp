// juez72.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool esValida(vector<vector<int>>& matriz, vector<bool>& marcas, int& k, int& i, int& contador, int& m) {
	bool valid = true;
	if (matriz[k][i] < 0) {
		valid = false;
	}
	if (contador > (m/3)) {
		valid = false;
	}
	if (marcas[i]) {
		valid = false;
	}
	return valid;
} 

void VA(vector<vector<int>>& matriz, vector<int>& sol, vector<int> & solMejor, vector<bool>& marcas, int k, int& n, int& m, int& hada, int& satisActual, int& satisMejor, int& contador, int& numComb) {
	for (int i = 0; i < n; i = i + 1) {
		sol[k] = i;
		if (k == i) {
			contador+= 1;
		}
		if (esValida(matriz, marcas, k, i, contador, m)) {
			marcas[i] = true;
			satisActual += matriz[k][i];		
			if (k == m - 1) {
				if (marcas[hada]) {				
					if (satisMejor < satisActual) {
						numComb = 1;
						satisMejor = satisActual;
						solMejor = sol;
					}
					else if (satisMejor == satisActual) {
						numComb += 1;
					}					
				}
			}
			else {
				VA(matriz, sol, solMejor, marcas, k + 1, n, m, hada, satisActual, satisMejor, contador, numComb);
			}
			marcas[i] = false;
			satisActual = satisActual - matriz[k][i];
		}
		if (k == i) {
			contador -= 1;
		}
	}
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		int m;
		cin >> m;
		int hada;
		cin >> hada;
		vector<vector<int>> matriz(m, vector<int>(n));
		for (int i = 0; i < m; i = i + 1) {
			for (int j = 0; j < n; j = j + 1) {
				cin >> matriz[i][j];
			}
		}
		vector<int> sol(m);
		vector<bool> marcas(n, false);
		vector<int> solMejor(n);
		int satisActual = 0;
		int satisMejor = 0;
		int contador = 0;
		int numComb = 0;
		VA(matriz, sol, solMejor, marcas, 0, n, m, hada, satisActual, satisMejor, contador, numComb);
		if (numComb == 0) {
			cout << "No";
		}
		else {
			cout << satisMejor << " " << numComb;
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
