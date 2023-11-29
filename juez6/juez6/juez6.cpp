// juez6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

void resolver(std::vector<int>& v1, std::vector<int>& v2) {
	std::vector<int> sol;
	int i = 0;
	int j = 0;
	while (i < v1.size() && j < v2.size()) {
		if (v1[i] < v2[j]) {
			sol.push_back(v1[i]);
			i = i + 1;
		}
		else if (v1[i] > v2[j]) {
			sol.push_back(v2[j]);
			j = j + 1;
		}
		else {
			sol.push_back(v1[i]);
			sol.push_back(v2[j]);
			i = i + 1;
			j = j + 1;
		}
	}
	while (i < v1.size()) {
		sol.push_back(v1[i]);
		i = i + 1;
	}
	while (j < v2.size()) {
		sol.push_back(v2[j]);
		j = j + 1;
	}
	for (int i = 0; i < sol.size(); i = i + 1) {
		std::cout << sol[i] << ' ';
	}
	std::cout << '\n';
}

void resuelveCaso() {
	int num1;
	int num2;
	std::cin >> num1;
	std::cin >> num2;
	std::vector<int> v1(num1);
	std::vector<int> v2(num2);
	for (int i = 0; i < num1; i = i + 1) {
		std::cin >> v1[i];
	}
	for (int i = 0; i < num2; i = i + 1) {
		std::cin >> v2[i];
	}
	resolver(v1, v2);
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
