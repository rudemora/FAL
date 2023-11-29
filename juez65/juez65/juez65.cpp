// juez65.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void VA(vector<int>& sol, vector<vector<int>>& v, vector<bool>& marcas, int& m, int& satisActual, int& satisMax, int k, vector<int>& acum) {
	for (int i = 0; i < m; i = i + 1) {
		sol[k] = i;
		if (!marcas[i]) {
			marcas[i] = true;
			satisActual += v[k][i];
			if (k == sol.size() - 1) {
				if (satisActual > satisMax) {
					satisMax = satisActual;
				}
			}
			else {
				if (satisActual + acum[k + 1] >= satisMax ) {
					VA(sol, v, marcas, m, satisActual, satisMax, k + 1, acum);
				}
			}
			marcas[i] = false;
			satisActual -= v[k][i];
		}
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
		vector<vector<int>> v(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
			}
		}
		vector<int> sol(n);
		vector<bool> marcas(m,false);
		int satisActual = 0;
		int satisMax = 0;
		for (int i = 0; i < n; i = i + 1) {
			satisMax += v[i][i];
		}
		int max;
		vector<int> acum(n);
		for (int i = 0; i < n; i++) {
			max = v[i][0];
			for (int j = 0; j < m; j++) {
				if (v[i][j] > max) {
					max = v[i][j];
				}
			}
			acum[i] = max;
		}
		for (int i = acum.size() - 2; i >= 0; i--) {
			acum[i] = acum[i] + acum[i + 1];
		}		
		VA(sol, v, marcas, m, satisActual, satisMax, 0, acum);
		cout << satisMax << "\n";
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
