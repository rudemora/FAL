// juez68.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void VA(vector<vector<int>>& trajes, vector<vector<int>>& zapatos, vector<bool>& marcasT, vector<bool>& marcasZ, int& preferenciaActual, int& preferenciaMax, vector<int>& acum, int k) {
	for (int i = 0; i < trajes.size(); i = i + 1) {
		if (!marcasT[i]) {
			marcasT[i] = true;
			for (int j = 0; j < zapatos.size(); j = j + 1) {
				if (!marcasZ[j]) {
					marcasZ[j] = true;
					preferenciaActual += trajes[k][i] * zapatos[k][j];
					if (k == trajes.size() - 1) {
						if (preferenciaActual > preferenciaMax) {
							preferenciaMax = preferenciaActual;
						}
						
					}
					else {
						if (preferenciaActual + acum[k + 1] > preferenciaMax) {
							VA(trajes, zapatos, marcasT, marcasZ, preferenciaActual, preferenciaMax, acum, k + 1);
						}
					}
					marcasZ[j] = false;
					preferenciaActual -= trajes[k][i] * zapatos[k][j];
				}
			}
			marcasT[i] = false;
		}
		
	}
}

void resuelveCaso() {
	int n;
	cin >> n;
	vector<vector<int>> trajes(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> trajes[i][j];
		}
	}
	vector<vector<int>> zapatos(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> zapatos[i][j];
		}
	}
	int preferenciaActual = 0;
	int preferenciaMax = 0;
	vector<bool> marcasT(n, false);
	vector<bool> marcasZ(n, false);
	for (int i = 0; i < trajes.size(); i++) {
		preferenciaMax += trajes[i][i] * zapatos[i][i];
	}
	int max;
	vector<int> acum(n);
	for (int i = 0; i < trajes.size(); i++) {
		max = trajes[i][0];
		for (int j = 0; j < trajes.size(); j++) {
			if (trajes[i][j] > max) {
				max = trajes[i][j];
			}
			
		}
		acum[i] = max;
	}
for (int i = 0; i < zapatos.size(); i++) {
		max = zapatos[i][0];
		for (int j = 0; j < zapatos.size(); j++) {
			if (zapatos[i][j] > max) {
				max = zapatos[i][j];
			}
			
		}
		acum[i] *= max;
	}
	for (int i = acum.size() - 2; i >= 0; i--) {
		acum[i] += acum[i + 1];
	}	
	VA(trajes, zapatos, marcasT, marcasZ, preferenciaActual, preferenciaMax, acum, 0);
	cout << preferenciaMax << "\n";
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
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
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
