// juez46.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct sol {
	vector<int> v;
	int changes;
};

sol resolver(vector<int>& v, const int& izq, const int& drcha) {
	if (izq == drcha)
		return { { v[izq] } , 0 };

	else if (izq + 1 == drcha) {
		if (v[izq] < v[drcha]) {
			return { { v[izq] , v[drcha] } , 0 };
		}
		else {
			return { { v[drcha] , v[izq] } , 1 };
		}
	}
	else {
		int changes = 0;
		int i = 0;
		int j = 0;
		int m = (izq + drcha) / 2;
		sol sol1 = resolver(v, izq, m);
		sol sol2 = resolver(v, m + 1, drcha);
		vector<int> v_aux(sol1.v.size() + sol2.v.size());
		while (i < sol1.v.size() || j < sol2.v.size()) {
			if (i < sol1.v.size() && j < sol2.v.size()) {

				if (sol1.v[i] < sol2.v[j]) {
					v_aux[i + j] = sol1.v[i++];

				}
				else {
					changes += (sol1.v.size() - i);
					v_aux[i + j] = sol2.v[j++];
				}
			}
			else if (i < sol1.v.size()) {
				v_aux[i + j] = sol1.v[i++];
			}
			else {
				v_aux[i + j] = sol2.v[j++];
			}
		}
		return { v_aux , sol1.changes + sol2.changes + changes };

	}

}

bool resuelveCaso() {
	int size;
	std::cin >> size;
	if (!std::cin) {
		return false;
	}
	vector<int> v(size);
	for (int i = 0; i < size; i++) {
		std::cin >> v[i];
	}
	std::cout << resolver(v, 0, v.size() - 1).changes << std::endl;
	return true;

}

int main() {
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