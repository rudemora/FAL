// juez4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

void resolver(std::vector<int>& v, int min, int numOp) {
	long long int suma = 0;
	int numdatos = 0;
	for (int i = 0; i < numOp; i = i + 1) {
		if (v[i] != min) {
			suma = suma + v[i];
			numdatos = numdatos + 1;
		}
	}
	std::cout << suma << ' ' << numdatos << '\n';
}

void resolverCaso() {
	int numOp;
	std::vector<int> v(1000);
	std::cin >> numOp;
	std::cin >> v[0];
	int min = v[0];
	for (int i = 1; i < numOp; i = i + 1) {
		std::cin >> v[i];
		if (min > v[i]) {
			min = v[i];
		}
	}
	resolver(v, min, numOp);
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
		resolverCaso();
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
