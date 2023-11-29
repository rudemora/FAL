// juez20.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

void resolver(std::vector<int>& v, int lectura) {
	int sumamax = 0;
	int suma = 0;
	int pos;
	for (int i = 0; i < lectura; i = i + 1) {
		suma = suma + v[i];
	}
	sumamax = suma;
	pos = 0;
	for (int i = lectura; i < v.size(); i = i + 1) {
		suma = suma - v[i - lectura];
		suma = suma + v[i];
		if (suma >= sumamax) { 
		sumamax = suma; 
		pos = i - lectura + 1;
		}
	}
	std::cout << pos << "\n";
}

bool resuelveCaso() {
	int num_pages;
	int lectura;
	std::cin >> num_pages >> lectura;
	if (num_pages == 0 && lectura == 0) {
		return false;
	}
	else {
		std::vector<int> v(num_pages);
		for (int i = 0; i < v.size(); i = i + 1) {
			std::cin >> v[i];
		}
		resolver(v, lectura);
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
