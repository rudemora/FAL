// juez39.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

int resolver(std::vector<int> v, int inicio, int final) {
	if (inicio >= final) {
		return v[inicio];
	}
	if (inicio + 1 >= final) {
		if (v[inicio] > v[final-1]) {
			return v[final-1];
		}
		else {
			return v[inicio];
		}
		
	}
	else {
		int medio = (inicio + final) / 2;
		if (v[medio - 1] > v[medio]) {
			return resolver(v, medio, final);
		}
		else {
			return resolver(v, inicio, medio);
		}
	}
}

bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (!std::cin) {
		return false;
	}
	else {
		std::vector<int> v(num);
		for (int i = 0; i < num; i = i + 1) {
			std::cin >> v[i];
		}
		int minimo = resolver(v, 0, num);
		std::cout << minimo << "\n";
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
	while(resuelveCaso());
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
