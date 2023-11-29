// juez52.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>

using namespace std;


bool unos(long long int n) {
	while ((n != 0) && (n % 10 != 1)) {
		n = n / 10;
	}
	if (n % 10 == 1) {
		return true;
	}
	else {
		return false;
	}
}

long long int recursion(long long int n) {
	if (n < 10) {
		if (n == 0) {
			return 1;
		}
		else {
			return n;
		}
	}
	else {
		if (unos(n / 10)) {
			return recursion(n / 10) * 9; 
		}
		else if (n % 10 == 0 || n % 10 == 1) {
			return recursion(n / 10) * 9 - 8;
		}
		else {
			return recursion(n / 10) * 9 - (9 - n % 10);
		}
	}
}


bool resuelveCaso() {
	long long int n;
	cin >> n;
	if (!cin) {
		return false;
	}
	else {
		long long int sol = recursion(n);
		cout << sol << "\n";
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
