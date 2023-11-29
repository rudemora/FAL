// juez61.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void mostrar(vector<int>& sol) {
	for (int i = 0; i < sol.size(); i = i+1) {
		if (sol[i] == 0) {
			cout << "azul ";
		}
		else if (sol[i] == 1) {
			cout << "rojo ";
		}
		else {
			cout << "verde ";
		}
	}
	cout << "\n";
}

bool esValida(int& altura, int& azul, int& rojo,int & verde,int k, vector<int>& sol, int& azulPuestas, int& rojoPuestas, int& verdePuestas) {
	bool valid = true;
	if (azulPuestas > azul) {
			valid = false;
			
	}
	else if (rojoPuestas > rojo) {
			valid = false;
	}
	else if (verdePuestas > verde || (sol[k-1] == 2 && sol[k] == 2)) {
			valid = false;
	}
	if (verdePuestas > azulPuestas) {
		valid = false;
	}
	
	return valid;

}

int VA(int& altura, int& azul, int& rojo, int& verde, int k, vector<int>& sol, int& azulPuestas, int& rojoPuestas, int& verdePuestas) {
	bool existSol = false;
	for (int i = 0; i < 3; i = i + 1) {	
		sol[k] = i;
		if (i == 0) {
			azulPuestas += 1;
		}
		else if (i == 1) {
			rojoPuestas += 1;
		}
		else if (i == 2) {
			verdePuestas += 1;
		}
		if (esValida(altura, azul, rojo, verde, k, sol, azulPuestas, rojoPuestas, verdePuestas)) {
			if (k == altura - 1) {
				if (rojoPuestas > (verdePuestas + azulPuestas)) {
					mostrar(sol);
					existSol = true;
				}
			}
			else {
				existSol = VA(altura, azul, rojo, verde, k + 1, sol, azulPuestas, rojoPuestas, verdePuestas);
			}
		}
		if (i == 0) {
			azulPuestas -= 1;
		}
		else if (i == 1) {
			rojoPuestas -= 1;
		}
		else if (i == 2) {
			verdePuestas -= 1;
		}
	}
	return existSol;
}

bool resuelveCaso() {
	int altura, azul, rojo, verde;
	cin >> altura >> azul >> rojo >> verde;
	if (altura == 0 && azul == 0 && rojo == 0 && verde == 0) {
		return false;
	}
	else {
		vector<int> sol(altura);
		int rojoPuestas = 0;
		int verdePuestas = 0;
		int azulPuestas = 0;
		if (rojo > 0) {
			sol[0] = 1;
			rojoPuestas = rojoPuestas + 1;
			bool existSol = VA(altura, azul, rojo, verde, 1, sol, azulPuestas, rojoPuestas,verdePuestas);
			cout << "\n";
			if (!existSol) {
				cout << "SIN SOLUCION\n";
			}
		}
		else {
			cout << "SIN SOLUCION\n";
		}
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
