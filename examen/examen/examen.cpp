// examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int recursivaNF(int num, int pot, int nuevo) {
	if (num < 10) {
		if (num % 2 == 0) {
			return nuevo;
		}
		else {
			return num*pot + nuevo ;
		}
	}
	else {
		int digito = num % 10;
		if (digito % 2 == 0) {
			return recursivaNF(num / 10, pot, nuevo);
		}
		else {
			return recursivaNF(num / 10, pot * 10, digito * pot + nuevo);
		}
	}
}

int recursivaF(int num) {
	if (num < 10) {
		if (num % 2 == 0) {
			return 0;
		}
		else {
			return num;
		}
	}
	else {
		int dig = num % 10;
		if (dig % 2 == 0) {
			return recursivaF(num / 10);
		}
		else {
			return recursivaF(num / 10) * 10 + dig;
		}
	}
}

bool resuelveCaso() {
	int num;
	cin >> num;
	if (!cin) {
		return false;
	}
	else {
		int sol1 = recursivaNF(num, 1, 0);
		int sol2 = recursivaF(num);
		cout << sol1 << " " << sol2 << "\n";
		return true;
	}
}

int main()
{
	while (resuelveCaso());
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
