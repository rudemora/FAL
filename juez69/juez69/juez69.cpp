// juez69.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void VA(vector<vector<int>>& v, vector<bool>& sol, int& superficieActual, int& maximaSuperficie, int& presupuestoActual, int& presupuesto, int k) {
	sol[k] = true;
	presupuestoActual += v[k][0];
	if (presupuestoActual <= presupuesto) {
		superficieActual += v[k][1];
		if (k == sol.size() - 1) {
			if (superficieActual > maximaSuperficie) {
				maximaSuperficie = superficieActual;
			}
		}
		else {
			VA(v, sol, superficieActual, maximaSuperficie, presupuestoActual, presupuesto, k + 1);
		}

		superficieActual -= v[k][1];
	}
	presupuestoActual -= v[k][0];
	sol[k] = false;
	if (k == sol.size() - 1) {
		if (superficieActual > maximaSuperficie) {
			maximaSuperficie = superficieActual;
		}
	}
	else {
		VA(v, sol, superficieActual, maximaSuperficie, presupuestoActual, presupuesto, k + 1);
	}
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin) {
		return false;
	}
	else {
		int presupuesto;
		cin >> presupuesto;
		int presupuestoActual = 0;
		vector<vector<int>> v(n, vector<int>(2));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> v[i][j];
			}
		}
		int superficieActual = 0;
		int maximaSuperficie = 0;
		vector<bool> sol(n);
		VA(v, sol, superficieActual, maximaSuperficie, presupuestoActual, presupuesto, 0);
		cout << maximaSuperficie << "\n";
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
