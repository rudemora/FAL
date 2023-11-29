// juez17.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

struct tSol {
	std::vector<int> inicios;
	int longmax;
	int numllanos;
};

tSol resolver(const std::vector<int>& v, int l) {
	std::vector<int> sol;
	int longmax = 0;
	int numllanos = 0;
	int max = v[v.size() - 1];
	int i = v.size() - 2;
	int longact = 1;
	int fin = 0;
	while (i >= 0) {
		if (max < v[i]) {
			longact = 1;
			max = v[i];
		}
		else if (max == v[i]) {
			longact = longact + 1;
			fin = i;	
			if (longact > longmax && longact >= l) {
				longmax = longact;
			}
		}
		else if (v[i] != max) {
			longact = 0;
		}
		if (longact == l) {
			numllanos = numllanos + 1;
			sol.push_back(fin + longact - 1);
		}
		i = i - 1;
	}
	return {sol , longmax, numllanos };
}
bool resuelveCaso() {
	int num;
	int l;
	std::cin >> num >> l;
	if (!std::cin) {
		return false;
	}
	else {
		std::vector<int> v(num);
		for (int i = 0; i < v.size(); i = i + 1) {
			std::cin >> v[i];
		}
		tSol sol = resolver(v, l);
		std::cout << sol.longmax << " " << sol.numllanos << " ";
		for (int i = 0; i < sol.inicios.size(); i = i + 1) {
			std::cout << sol.inicios[i] << " ";
		}
		std::cout << "\n";
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
