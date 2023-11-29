// juez29.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

int resolver(std::vector<int>& v, int k) {
	int longact = 0;
	int longmax = 0;
	int i = 0;
	int longseg = 0;
	while (i < v.size()) {
		if (v[i] % 2 == 0) {
			longseg += 1;
			if (longseg > k) {
				longact = k;
				longseg = k;
			}
			else {
				longact += 1;
			}
			i = i + 1;
		}
		else if (v[i] % 2 == 1) {
			longseg = 0;
			longact += 1;
			i = i + 1;
		}
		if (longact >= longmax) {
			longmax = longact;
		}

	}
	return longmax;
}

void resuelveCaso() {
	int num_elems;
	int k;
	std::cin >> num_elems >> k;
	std::vector<int> v(num_elems);
	for (int i = 0; i < num_elems; i = i + 1) {
		std::cin >> v[i];
	}
	int sol = resolver(v, k);
	std::cout << sol << "\n";
}

int main()
{
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i = i + 1) {
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
