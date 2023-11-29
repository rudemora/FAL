// juez9.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

void resolver(std::vector<int>& v, std::vector<long long int>& r, int ini) {
	int quest;
	std::cin >> quest;
	std::vector<long long int> aux(v.size() + 1);
	aux[0] = 0;
	for (int i = 0; i < v.size(); i = i + 1) {
		aux[i + 1] = v[i] + aux[i];
	}
	int first_y;
	int last_y;
	for (int i = 0; i < quest; i = i + 1) {
		std::cin >> first_y >> last_y;
		r.push_back(aux[last_y - ini + 1] - aux[first_y - ini]);
	}
}

bool resuelveCaso() {
	int ini;
	int final;
	std::cin >> ini >> final;
	if (ini == 0 && final == 0) {
		return false;
	}
	else {
		std::vector<int> v(final - ini + 1);
		std::vector<long long int> r;
		for (int i = 0; i < v.size(); i = i + 1) {
			std::cin >> v[i];
		}
		resolver(v, r, ini);
		for (int i = 0; i < r.size(); i = i + 1) {
			std::cout << r[i] << '\n';
		}
		std::cout << "---\n";
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
