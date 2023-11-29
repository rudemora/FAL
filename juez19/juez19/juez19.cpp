// juez19.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


//Coste función resolver: las primeras tres instrucciones son asginaciones con coste constante. Para determinar el coste del primre bucle while necesitamos conocer el número de vueltas que se dan y 
//y el coste de cada vuelta. En el primer bucle for se dan tantas vueltas como sea el número vagon_max, la instrucción que se ejecuta dentro del bucle tiene coste constante. Las siguientes dos 
//instrucciones tienen ambas coste constante. En el segundo bucle for se dan v.size() - vagon_max vueltas. En cada vuelta, las primeras dos instrucciones son de coste constante y el if también es de coste
//constante, son asginaciones e incrementos. Por tanto, el coste del bucle es O(v.size() - vagon_max) = O(v.size()), luego es coste lineal.


#include <iostream>
#include <vector>
#include <fstream>

struct tSol {
	int vagon;
	int ganancia;
};

tSol resolver(std::vector<int>& v, int vagon_max) {
	int suma = 0;
	int sumamax = 0;
	int inicio;
	for (int i = 0; i < vagon_max; i = i + 1) {
		suma = suma + v[i];
	}
	sumamax = suma;
	inicio = 0;
	for (int i = vagon_max; i < v.size(); i = i + 1) {
		suma = suma - v[i - vagon_max];
		suma = suma + v[i];
		if (suma >= sumamax) {
			sumamax = suma;
			inicio = i - vagon_max + 1;
		}
	}
	return { inicio,  sumamax};
}

void resuelveCaso() {
	int num;
	std::cin >> num;
	int vagon_max;
	std::cin >> vagon_max;
	std::vector<int> v(num);
	for (int i = 0; i < num; i = i + 1) {
		std::cin >> v[i];
	}
	tSol sol = resolver(v, vagon_max);
	std::cout << sol.vagon << " " << sol.ganancia << "\n";
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
