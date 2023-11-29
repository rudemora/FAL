// juez8.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>
void resolver(std::vector<int>& v1, std::vector<int>& v2, std::vector<int>& v3) {
	int i = 0;
	int j = 0;
	while (i < v1.size() && j < v2.size()) {
		if (v1[i] < v2[j]) {
			v3.push_back(v1[i]);
			i = i + 1;
		}
		else if (v1[i] > v2[j]) {
			v3.push_back(v2[j]);
			j = j + 1;
		}
		else {
			i = i + 1;
			j = j + 1;
		}
	}
	while (i < v1.size()) {
		v3.push_back(v1[i]);
		i = i + 1;
	}
	while (j < v2.size()) {
		v3.push_back(v2[j]);
		j = j + 1;
	}
}

void resuelveCaso() {
	std::vector<int> v1;
	std::vector<int> v2;
	int num;
	std::cin >> num;
	while (num != 0) {
		v1.push_back(num);
		std::cin >> num;
	}
	std::cin >> num;
	while (num != 0) {
		v2.push_back(num);
		std::cin >> num;
	}
	std::vector<int> v3;
	resolver(v1, v2, v3);
	for (int i = 0; i < v3.size(); i = i + 1) {
		std::cout << v3[i] << " ";
	}
	std::cout << "\n";
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
