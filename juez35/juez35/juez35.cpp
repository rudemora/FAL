// juez35.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>

int resolverN(int num, int maxActual) {
	if (num < 10 && num>= maxActual) {
		return num;
	}
	else if (num < 10 && num < maxActual) { 
		return 0; 
	}
	else {
		if (num % 10 >= maxActual) {
			return 10*resolverN(num / 10, num%10) + num%10;
		}
		else {
			return resolverN(num / 10, maxActual);
		}
	}
} 

int resolver(int num, int maxActual, int nuevo, int potencia) {
	if (num < 10) {
		if (num >= maxActual) {
			nuevo = nuevo + num * potencia;
			return nuevo;
		}
		else {
			return nuevo;
		}
	}
	else {
		if (num % 10 >= maxActual) {
			nuevo = nuevo + num%10 * potencia;
			return resolver(num / 10, num % 10, nuevo, potencia * 10);
		}
		else {
			return resolver(num / 10, maxActual, nuevo, potencia);
		}
	}
}

void resuelveCaso() {
	int num;
	std::cin >> num;
	int sol = resolver(num, 0, 0, 1);
	int solN = resolverN(num, 0);
	std::cout << sol << " " << solN << "\n";
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
