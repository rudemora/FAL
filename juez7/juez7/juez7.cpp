// juez7.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

void resolver(std::vector<int>& ventas, int primer_ano, std::vector<int>& anos) {
	std::vector<int> anos_sol;
	int max = ventas[0];
	for (int i = 0; i < ventas.size() - 1; i = i + 1) {
		if (max < ventas[i]) {
			max = ventas[i];
		}
		//std::cout << ventas[i] << "l";
		if (ventas[i + 1] > max) {
			anos_sol.push_back(primer_ano + i + 1);
		}
	}
	anos = anos_sol;
}

void resuelveCaso() {
	int primer_ano;
	int segundo_ano;
	std::cin >> primer_ano;
	std::cin >> segundo_ano;
	std::vector<int> ventas(segundo_ano - primer_ano + 1);
	for (int i = 0; i < ventas.size(); i = i + 1) {
		std::cin >> ventas[i];
	}
	std::vector<int> anos;
	resolver(ventas, primer_ano, anos);
	for (int i = 0; i < anos.size(); i = i + 1) {
		std::cout << anos[i] << " ";
	}
	std::cout << '\n';
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
