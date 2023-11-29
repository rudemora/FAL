// juez34.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>

long long int recursivaNOfinal(long long int num) {
	if (num < 10) {
		if (num % 2 == 1) {
			return num;
		}
		else return 0;
	}
	else {
		int sol;
		if ((num%10) % 2 == 1) {
			sol = num % 10;;
			return (10 * recursivaNOfinal(num / 10)) + sol;
		}
		else {
			return recursivaNOfinal(num / 10);
		}
	}
}

long long int recursivafinal(long long int num, long long int nuevo, long long int pot) {
	if (num < 10) {
		if (num % 2 == 1) {
			return num * pot + nuevo;
		}
		else return nuevo;
	}
	else {
		if ((num % 10) % 2 == 1) {
			nuevo = ((num % 10) * pot) + nuevo;
			return recursivafinal(num / 10, nuevo, pot * 10);
		}
		else {
			return recursivafinal(num / 10, nuevo, pot);
		}
	}
}

bool resuelveCaso() {
	long long int num;
	std::cin >> num;
	if (!std::cin) {
		return false;
	}
	else {
		long long int sol1 = recursivaNOfinal(num);
		long long int sol2 = recursivafinal(num, 0, 1);
		std::cout << sol1 << " " << sol2 << "\n";
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
