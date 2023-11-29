// juez58.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

void mostrar(std::vector<char>& sol) {
	for (int i = 0; i < sol.size(); i = i + 1) {
		std::cout << sol[i];
	}
	std::cout << "\n";
}

void VA(int& m, int& n, int k, std::vector<char>& sol, std::vector<bool>& marcas) {
	for (char i = 'a'; i < 'a' + m; i = i + 1) {
		sol[k] = i;
		if (!marcas[i - 'a']) {
			marcas[i - 'a'] = true;
			if (k == n - 1) {
				mostrar(sol);
			}
			else {
				VA(m, n, k + 1, sol, marcas);
			}
			marcas[i - 'a'] = false;
		}
		
	}
	
}

bool resuelveCaso() {
	int m;
	std::cin >> m;
	if (!std::cin) {
		return false;
	}
	else {
		int n;
		std::cin >> n;
		std::vector<char> sol(n);
		std::vector<bool> marcas(m,false);
		VA(m, n, 0, sol, marcas);
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
