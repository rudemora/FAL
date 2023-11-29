// last_digit.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

int main()
{
	int numCasos;
	int num;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i = i + 1) {
		std::cin >> num;
		if (num >= 5) {
			std::cout << "0" << std::endl;
		}
		else if (num == 0) {
			std::cout << "1" << std::endl;
		}
		else if (num <= 2 || num == 4) {
			std::cout << num << std::endl;
		}
		else if (num == 3) {
			std::cout << "6" << std::endl;
		}
	}
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
