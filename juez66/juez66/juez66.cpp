// juez66.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void VA(vector<vector<int>>& v, vector<int>& sol, vector<bool>& marcas, int& tiempoActual, int& minimTiempo, int k) {
	for (int i = 0; i < v.size(); i++) {
		sol[k] = i;
		if (!marcas[i]) {
			marcas[i] = true;
			tiempoActual += v[k][i];
			if (k == v.size() - 1) {
				if (tiempoActual < minimTiempo) {
					minimTiempo = tiempoActual;
				}
			}
			else {
				VA(v, sol, marcas, tiempoActual, minimTiempo, k + 1);
			}
			marcas[i] = false;
			tiempoActual -= v[k][i];
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
		vector<vector<int>> v(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		int tiempoActual = 0;
		int minimTiempo = 0;
		for (int i = 0; i < n; i++) {
			minimTiempo += v[i][i];
		}
		vector<bool> marcas(n, false);
		vector<int> sol(n);
		VA(v, sol, marcas, tiempoActual, minimTiempo, 0);
		cout << minimTiempo << "\n";
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
