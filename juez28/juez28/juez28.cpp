// juez28.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

int resolver(const std::vector<int>& v) {
	int longitudmax = 1;
	int inicio = 0;
	int longitudactual = 2;
	int tamano = v.size();
	if (tamano == 2) {
		return 2;
	}
	if (tamano == 0) {
		return 0;
	}
	while (inicio < (tamano - 2)) {
		if (v[inicio] < v[inicio + 1] && v[inicio + 1] < v[inicio + 2]) {
			longitudactual = 2;
		}
		else {
			longitudactual = longitudactual + 1;
		}
		if (longitudactual > longitudmax) {
				longitudmax = longitudactual;
		}
		inicio = inicio + 1;
	}
	return longitudmax;
}

void resuelveCaso() {
	int longitud;
	std::cin >> longitud;
	std::vector<int> v(longitud);
	for (int i = 0; i < longitud; i = i + 1) {
		std::cin >> v[i];
	}
	int sol = resolver(v);
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
