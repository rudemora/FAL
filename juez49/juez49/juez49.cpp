// juez49.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int resolver(vector<int>& v, int ini, int fin) {
	if (ini == fin) {
		return (v[ini] % 2 == 0);
	}
	else if (ini + 1 == fin) {
		return (v[ini] % 2 == 0) + (v[fin] % 2 == 0);
	}
	else {
		int medio = (ini + fin) / 2;
		int izq = resolver(v, ini, medio);
		int drcha = resolver(v, medio + 1, fin);
		if (izq != -1 && drcha != -1 && (abs(izq - drcha) <= 2)) {
			return izq + drcha;
		}
		else {
			return -1;
		}
	}
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int num = 0;
		num = resolver(v, 0, v.size() - 1);
		if (num != -1) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
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
