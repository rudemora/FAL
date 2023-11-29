// juez71.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void mostrar(vector<int>& sol) {
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << " ";
	}
}

void VA(vector<vector<int>>& v, vector<bool>& marcas, vector<int>& sol, int& t1, int& t2, int& tiempoIda, int& tiempoVuelta, bool& exito, int& satis, int& satisMax, int k) {
	for (int i = 0; i < v.size(); i++) {
		sol[k] = i;
		if (!marcas[i]) {
			marcas[i] = true;
			if (tiempoIda  == t1) {
				if (tiempoVuelta == t2) {
					if (k == sol.size() - 1) {
						if (satisMax < satis) {
							satisMax = satis;
							exito = true;
						}
					}
					else {
						VA(v, marcas, sol, t1, t2, tiempoIda, tiempoVuelta, exito, satis, satisMax, k + 1);
					}
				}
				else if (tiempoVuelta + v[i][0] <= t2) {
					tiempoVuelta += v[i][0];
					satis += v[i][1];
					if (k == sol.size() - 1) {
						if (satisMax < satis) {
							satisMax = satis;
							exito = true;
						}
					}
					else {
						VA(v, marcas, sol, t1, t2, tiempoIda, tiempoVuelta, exito, satis, satisMax, k + 1);
					}
					satis -= v[i][1];
					tiempoVuelta -= v[i][0];
				}
			}
			else if (tiempoIda + v[i][0] <= t1) {
				tiempoIda += v[i][0];
				satis += v[i][1];
				if (k == sol.size() - 1) {
					if (satisMax < satis) {
						satisMax = satis;
						exito = true;
					}
				}
				else {
					VA(v, marcas, sol, t1, t2, tiempoIda, tiempoVuelta, exito, satis, satisMax, k + 1);
				}
				satis -= v[i][1];
				tiempoIda -= v[i][0];
			}
			marcas[i] = false;
		}
	}
}

bool resuelveCaso() {
	int n;
	cin >> n;
	int t1;
	cin >> t1;
	int t2;
	cin >> t2;
	if (n == 0 && t1 == 0 && t2 == 0) {
		return false;
	}
	else {
		
		vector<vector<int>> v(n, vector<int>(2));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> v[i][j];
			}
		}
		bool exito = false;
		vector<int> sol(n);
		vector<bool> marcas(n);
		int tiempoIda = 0;
		int tiempoVuelta = 0;
		int satis = 0;
		int satisMax = 0;
		VA(v, marcas, sol, t1, t2, tiempoIda, tiempoVuelta, exito, satis, satisMax, 0);
		if (!exito) {
			cout << "Imposible";
		}
		else {
			cout << satisMax;
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
