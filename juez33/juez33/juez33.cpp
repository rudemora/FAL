// juez33.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>

int resolverNOfinal(int num1, int num2) {
	if (num1 < 10 && num2 < 10) {
		return (num1 + num2) % 10;
	}
	else {
		int dig1 = num1 % 10;
		int dig2 = num2 % 10;
		int digito = (num1 + num2) % 10;
		return 10 * resolverNOfinal(num1 / 10, num2 / 10) + digito;
	}
}
int resolverfinal(int num1, int num2, int pot, int nuevo) {
	if (num1 < 10 && num2 < 10) {
		return ((num1 + num2) % 10) * pot + nuevo;
	}
	else {
		int dig1 = num1 % 10;
		int dig2 = num2 % 10;
		nuevo += ((num1 + num2) % 10) * pot;
		return resolverfinal(num1 / 10, num2 / 10, pot * 10, nuevo );
	}
}

void resuelveCaso() {
	int num1;
	int num2;
	std::cin >> num1 >> num2;
	int sol1 = resolverfinal(num1, num2, 1, 0);
	int sol2 = resolverNOfinal(num1, num2);
	std::cout << sol1 << " " << sol2 << "\n";
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
