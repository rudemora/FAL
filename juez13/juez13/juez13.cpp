// juez13.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
//El coste de este programa es lineal. Las primeras tres instrucciones de la función tienen coste constante. Calculamos el coste del bucle for: coste de cada vuelta 
//multiplicado por el número de vueltas (n). El coste de cada vuelta es constante pues dentro del if hay una suma en longactual, de coste lineal, y el if anidado tiene 
//también coste constante pues las instrucciones que hay dentro de él son asignaciones y sumas, de coste constante. El else también tiene coste constante. Entonces, el 
//coste de cada vuelta es constante y el número de vueltas es n. Por tanto, el coste de la función resolver es lineal en el número de datos introducidos; O(n).

#include <iostream>
#include <vector>
#include <fstream>



std::pair<int, int> resolver(const std::vector<int>& v, int altura) {
	int longmax = 0;
	int inimax = 0;
	int longactual = 0;
	for (int i = 0; i < v.size(); i = i + 1) {
		if (v[i] > altura) {
			longactual += 1;
			if (longactual > longmax) {
				longmax = longactual;
				inimax = i - longactual + 1;
			}
		}
		else {
			longactual = 0;
		}
	}
	return { inimax, inimax + longmax - 1 };
}

void resuelveCaso() {
	int num_edif;
	int altura;
	std::cin >> num_edif >> altura;
	std::vector<int> v(num_edif);
	for (int i = 0; i < v.size(); i = i + 1) {
		std::cin >> v[i];
	}
	std::pair<int,int> sol = resolver(v, altura);
	std::cout << sol.first << " " << sol.second << "\n";
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
