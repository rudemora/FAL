// juez27.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

int resolver(std::vector<int>& v, int k) {
	int positivosizq = 0;
	int positivosdcha = 0;
	int contador = 0;
	for (int i = 0; i < k/2; i = i + 1) {
		if (v[i] > 0) {
			positivosizq = positivosizq + 1;
		}
	}
	for (int i = k / 2; i < k; i = i + 1) {
		if (v[i] > 0) {			
			positivosdcha = positivosdcha + 1;
		}
	}
	if (positivosizq >= positivosdcha) {
		contador = contador + 1;
	}
	for (int i = k; i < v.size(); i = i + 1) {
		if (v[i - k] > 0) {
			positivosizq = positivosizq - 1;
		}
		if (v[i] > 0) {
			positivosdcha = positivosdcha + 1;
		}
		if (v[k/2 + i-k] > 0) {
			positivosizq = positivosizq + 1;
			positivosdcha = positivosdcha - 1;
		}
		if (positivosizq >= positivosdcha) {
			contador = contador + 1;
		}
	}
	return contador;
}

bool resuelveCaso() {
	int longitud;
	std::cin >> longitud;
	if (longitud == 0) {
		return false;
	}
	else {
		int k;
		std::cin >> k;
		std::vector<int> v(longitud);
		for (int i = 0; i < longitud; i = i + 1) {
			std::cin >> v[i];
		}
		int sol = resolver(v, k);
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
