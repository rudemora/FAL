// juez14.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

int resolver(std::vector<int>& v) {
	std::sort(v.begin(), v.end());
	int max = 0;
	long long int cont = 1;
	int num = v[0];
	for (int i = 1; i < v.size(); i = i + 1) {
		if (v[i] == v[i - 1]) {
			cont = cont + 1;
			if (cont > max) {
				max = cont;
				num = v[i];
			}
		}
		else {
			cont = 1;
		}
	}
	return num;
}

bool resuelveCaso() {
	int num_accid;
	std::cin >> num_accid;
	if (num_accid == -1) {
		return false;
	}
	else {
		std::vector<int> v(num_accid);
		for (int i = 0; i < v.size(); i = i + 1) {
			std::cin >> v[i];
		}
		int sol = resolver(v);
		std::cout << sol << "\n";
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
