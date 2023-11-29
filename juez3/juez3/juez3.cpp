// juez3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream> 

bool resolver(const std::vector<int>& v, int punto) {
	int max = v[0];
	for (int i = 1; i <= punto; i = i + 1) {
		if (max < v[i]) {
			max = v[i];
		}
	}
	int pos = punto + 1;
	bool find = (max >= v[pos]);
	while (!find && pos < v.size()) {
		pos = pos + 1;
	}
	if (pos == v.size() + 1) {
		return true;
	}
	else {
		return false;
	}
}

void resuelveCaso() {
	int tam;
	std::cin >> tam;
	std::vector<int> v(tam);
	int punto;
	std::cin >> punto;
	for (int i = 0; i < tam; i = i + 1) {
		std::cin >> v[i];
	}
	bool resultado = resolver(v, punto);
	if (resultado == true) {
		std::cout << "NO" << '\n';
	}
	else {
		std::cout << "SI" << '\n';
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

	int num;
	std::cin >> num;
	for (int i = 0; i < num; i = i + 1) {
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
