// juez22.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
struct tSol {
	int maxpruebas;
	int ultper;
};

tSol resolver(std::vector<int>& v) {
	int i = 1;
	int max = 0;
	int longitud = 0;
	int longitudmax = 0;
	int final = 0;
	while (i < v.size()) {
		if (v[max] >= v[i]) {
			longitud = longitud + 1;
			if (longitud > longitudmax) {
				longitudmax = longitud;
				final = i;
			}
			if (longitud == longitudmax) {
				final = i;
			}
		}
		else {
			max = i;
			longitud = 0;
			if (longitud == longitudmax) {
				final = i;
			}
			
		}
		i = i + 1;
	}
	return {longitudmax, final - longitudmax + 1};
}
bool resuelveCaso() {
	int num; 
	std::cin >> num;
	if (num == 0) {
		return false;
	}
	else {
		std::vector<int> v(num);
		for (int i = 0; i < v.size(); i = i + 1) {
			std::cin >> v[i];
		}
		tSol sol = resolver(v);
		std::cout << sol.maxpruebas << " " << sol.ultper << "\n";
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
