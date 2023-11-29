// ejercicio59.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

void mostrar(std::vector<int>& sol) {
	for (int i = 0; i < sol.size(); i = i + 1) {
		if (sol[i] == 0) {
			std::cout << "azul ";
		}
		else if (sol[i] == 1) {
			std::cout << "rojo ";
		}
		else {
			std::cout << "verde ";

		}
	}
	std::cout << "\n";
}

void resolver(int num, int k, std::vector<int>& sol) {
	for (int i= 0; i < 3; i = i + 1) {
		sol[k] = i;
		if (k == num - 1) {
			mostrar(sol);
		}
		else {
			resolver(num, k + 1, sol);
		}
	}
}

bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (num == 0) {
		return false;
	}
	else {
		std::vector<int> sol(num);
		resolver(num, 0, sol);
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
