// juez31.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>

int recursiva(int num) {
	if (num % 2 == 0 && num<10) {
		return num + 1;
	}
	else if (num % 2 == 1 && num<10) {
		return num - 1;
	}
	else {
		return 10 * recursiva(num/10) +  recursiva(num % 10);
	}

}	

int recursivaF(int num, int nuevo, int pot) {
	int digito;
	if (num % 2 == 0) digito = num % 10 + 1;
	else digito = num % 10 - 1;
	if (num < 10) {
		return digito * pot + nuevo;
	}
	else {
		return recursivaF(num / 10, digito * pot + nuevo, 10 * pot);
	}
}

void resolver() {
	int valor;
	std::cin >> valor;
	int sol = recursiva(valor);
	//int sol = recursivaF(valor, 0, 1);
	std::cout << sol << "\n";
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
		resolver();
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
