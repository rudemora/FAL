// juez26.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

int resolver(std::vector<bool>& v, int k) {
	int longmin = v.size() +1;
	int contador = 0;
	int pos = v.size() + 1;
	int i = 0;
	int inicio = 0;
	while (i < v.size() && pos == v.size() + 1) {
		if (v[i]) {
			if (contador == 0) {
				inicio = i;
			}
			contador = contador + 1;
		}
		if (contador == k) {
			pos = i - inicio + 1;
		}
		i = i + 1;
	}
	if (pos < longmin) {
		longmin = pos;
	}
	while (i < v.size()) {
		if (v[i]) {
			inicio = inicio + 1;
			while (!v[inicio]) {
				inicio = inicio + 1;
			}
			pos = i - inicio + 1;
			if (pos < longmin) {
				longmin = pos;
			}
		}
		i = i + 1;
	}
	return longmin;
}

bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (num == -1) {
		return false;
	}
	else {
		std::vector<bool> v(num);
		int value;
		for (int i = 0; i < num; i = i + 1) {
			std::cin >> value;
			if (value == 0) {
				v[i] = false;
			}
			else {
				v[i] = true;
			}
		}
		int k;
		std::cin >> k;
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
