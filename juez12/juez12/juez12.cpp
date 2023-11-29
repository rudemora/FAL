// juez12.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
 

//COMPLEJIDAD: tenemos 5 bucles secuenciales, cogemos el que mayor (máximo) coste tenga entre todos. Cogemos el tercer bucle, recorre todo v, luego ese bucle tiene
// orden n, siendo n el número de etapas y dentro del bucle el orden es constante. El coste es lineal también respecto al número de preguntas m pues en el cuarto
// bucle se recorre el vector, orden m y dentro del bucle el if tiene orden constante.

#include <iostream>
#include <vector>
#include <fstream>
bool resuelveCaso() {
	int num_etapas;
	std::cin >> num_etapas;
	if (num_etapas == -1) {
		return false;
	}
	else {
		std::vector<int> v(num_etapas);
		int preguntas;
		for (int i = 0; i < num_etapas; i = i + 1) {
			std::cin >> v[i];
		}
		std::cin >> preguntas;
		std::vector<long long int> quest(preguntas);
		for (int i = 0; i < preguntas; i = i + 1) {
			std::cin >> quest[i];
		}
		std::vector<long long int> aux(num_etapas + 1);
		aux[0] = 0;
		for (int i = 0; i < v.size(); i = i + 1) {
			aux[i + 1] = aux[i] + v[i];
		}
		for (int i = 0; i < quest.size(); i = i + 1) {
			if (quest[i] != aux.size()) {
				quest[i] = aux[aux.size() - 1] - aux[quest[i] - 1] ;
			}
			else {
				quest[i] = 0;
			}
		}
		for (int i = 0; i < quest.size(); i = i + 1) {
			std::cout << quest[i] << '\n';
		}
		std::cout << "---\n";
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
	while(resuelveCaso());
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
