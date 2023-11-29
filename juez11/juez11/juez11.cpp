// juez11.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
void resolver(std::vector<int>& v, std::vector<int>& r, int punt_max) {
	std::vector<int> aux(punt_max, 0);
	int cont = 0;
	for (int i = 0; i < v.size(); i = i + 1) {
		aux[v[i] - 1] = aux[v[i] - 1] + 1;
		if (cont < aux[v[i] - 1]) {
			cont = aux[v[i] - 1];
		}
	}
	for (int i = aux.size() -1; i >= 0; i = i - 1) {
		if (aux[i] == cont) {
			r.push_back(i + 1);
		}
	}
}

bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (num == -1) {
		return false;
	}
	else {
		int punt_max;
		std::cin >> punt_max;
		std::vector<int> v(num);
		std::vector<int> r;
		for (int i = 0; i < num; i = i + 1) {
			std::cin >> v[i];
		}
		resolver(v, r, punt_max);
		for (int i = 0; i < r.size() ; i = i + 1) {
			std::cout << r[i] << " ";
		}
		std::cout << '\n';
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
