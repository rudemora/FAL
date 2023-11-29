// juez24.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

struct tSol {
	int in_medio;
	int in_alto;
};
tSol resolver(std::vector<int> &v, int peso_medio, int peso_mayor) {
	int indice_med = 0;
	int indice_gra = 0;
	int aux;
	for (int i = 0; i < v.size(); i = i + 1) {
		if (v[i] < peso_medio) {
			aux = v[indice_med];
			v[indice_med] = v[i];
			v[i] = aux;
			indice_med = indice_med + 1;
		}
	}
	indice_gra = indice_med;
	for (int i = indice_med; i < v.size(); i = i + 1) {
		if (v[i] < peso_mayor ) {
			aux = v[indice_gra];
			v[indice_gra] = v[i];
			v[i] = aux;
			indice_gra = indice_gra + 1;
		}
	}
	return { indice_med, indice_gra };
}

bool resuelveCaso() {
	int num;
	int peso_medio;
	int peso_mayor;
	std::cin >> num >> peso_medio >> peso_mayor;
	if (!std::cin) {
		return false;
	}
	else {
		std::vector<int> v(num);
		for (int i = 0; i < num; i = i + 1) {
			std::cin >> v[i];
		}
		tSol sol = resolver(v, peso_medio, peso_mayor);
		std::sort(v.begin(), v.begin() + sol.in_medio);
		for (int i = 0; i < sol.in_medio; i = i + 1) {
			std::cout << v[i] << " ";
		}
		std::sort(v.begin() + sol.in_medio, v.begin() + sol.in_alto);
		std::cout << "\n";
		for (int i = sol.in_medio; i < sol.in_alto; i = i + 1) {
			std::cout << v[i] << " ";
		}
		std::sort(v.begin() + sol.in_alto, v.end());
		std::cout << "\n";
		for (int i = sol.in_alto; i < v.size(); i = i + 1) {
			std::cout << v[i] << " ";
		}
		std::cout << "\n---\n";
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
