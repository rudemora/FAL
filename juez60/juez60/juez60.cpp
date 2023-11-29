// ejercicio59.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

// El árbol tiene 3 ramas pero dos de ellas las podamos al exigir que la primera torre debe ser roja,
// la longitud de cada rama es de 3 (azul, rojo y verde) pero cuando en una rama haya dos un verde, la subrama
// se compondrá solo de rojo y azul (podamos la verde) para que no haya dos verdes seguidos. 



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

bool esValida(std::vector<int> & sol, int i, int k) {
	if (sol[k - 1] == 2 && i == 2) {
		return false;
	}
	else {
		return true;
	}
}

void resolver(int num, int k, std::vector<int>& sol) {
	for (int i = 0; i < 3; i = i + 1) {
		if (esValida(sol, i, k)) {
			sol[k] = i;
			if (k == num - 1) {
				mostrar(sol);
			}
			else {
				resolver(num, k + 1, sol);
			}
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
		sol[0] = 1;
		if (num == 1) {
			mostrar(sol);
		}
		else {
			resolver(num, 1, sol);
		}
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
