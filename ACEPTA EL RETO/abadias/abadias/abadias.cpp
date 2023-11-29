// abadias.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>

void(resolver(int num)) {
	std::vector<int> v(num);
	for (int i = 0; i < num; i = i + 1) {
		std::cin >> v[i];
	}
	int contador = 0;
	int max = v.size() - 1;
	for(int i = v.size() - 2; i >= 0; i = i + 1) {
		if (v.size() - 3 > max) {

		}
	}
	std::cout << contador << std::endl;
}

bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (num == 0) {
		return false;
	}
	else {
		resolver(num);
		return true;
	}
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
