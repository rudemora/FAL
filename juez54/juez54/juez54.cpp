// juez54.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int resolver(int a, int b, vector<vector<int>>& v) {
	if (b == 0 || a == b) {
		v[a][b] = 1;
		return v[a][b];
	}
	else if (b == 1 || b == a - 1) {
		v[a][b] = a;
		return v[a][b];
	}
	else {
		if (v[a - 1][b] == -1) {
			v[a - 1][b] = resolver(a - 1, b, v);
		}
		if (v[a - 1][b - 1] == -1) {
			v[a - 1][b - 1] = resolver(a - 1, b - 1, v);
		}
		v[a][b] = v[a - 1][b] + v[a - 1][b - 1];
		return v[a][b];
	}
}

bool resuelveCaso() {
	int a;
	cin >> a;
	if (!cin) {
		return false;
	}
	else {
		int b;
		cin >> b;
		vector<vector<int>> v(a + 1, vector<int>(b + 1, -1));
		int sol = resolver(a, b, v);
		cout << sol << "\n";
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
