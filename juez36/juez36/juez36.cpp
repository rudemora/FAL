// juez36.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>

struct tSol {
	long long int suma;
	bool sol;
};
tSol interesante(int num, int sumaD) {
	if (num < 10) {
		if ((sumaD % num) == 0) {
			return { num, true };
		}
		else {
			return { num, false };
		}
	}
	else {
		if (sumaD %(num%10) == 0) {
			tSol sumaI = interesante(num / 10, num % 10 + sumaD);
			if (sumaI.suma % (num % 10) == 0) {
				return { sumaI.suma + (num % 10), sumaI.sol };
			}
			else {
				return { sumaI.suma + (num % 10), false };
			}
		}
		else {
			return { sumaD, false };
		}
	}
}

void resolver() {
	int num;
	std::cin >> num;

	if (interesante(num, 0).sol) {
		std::cout << "SI\n";
	}
	else {
		std::cout << "NO\n";
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
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i = i + 1) {
		resolver();
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
