// juez23.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

struct tSol {
	int num_sup;
	std::vector<int> sup;
};

tSol resolver(std::vector<int>& v, int l) {
	std::vector<int> aux;
	int num_sup = 0;
	int i = 1;
	int longitud = 1;
	while (i < v.size()) {
		if ((v[i] == v[i - 1]) || (v[i] - 1 == v[i - 1]) || (v[i] == v[i -1] - 1)) {
			longitud = longitud + 1;
		}
		else {
			longitud = 1;
		}
		if (longitud == l) {
			num_sup = num_sup + 1;
			aux.push_back(i - longitud + 1);
		}
		i = i + 1;
	}

	return { num_sup, aux };
}

bool resuelveCaso() {
	int num; 
	int l;
	std::cin >> num >> l;
	if (num == 0 && l == 0) {
		return false;
	}
	else {
		std::vector<int> v(num);
		for (int i = 0; i < v.size(); i = i + 1) {
			std::cin >> v[i];
		}
		tSol sol = resolver(v, l);
		std::cout << sol.num_sup << " ";
		for (int i = 0; i < sol.sup.size(); i = i + 1) {
			std::cout << sol.sup[i] << " ";
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
