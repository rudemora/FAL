// juez2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>
//using namespace std;

void resolver(int num, std::string nacion) {
	std::vector<std::string> v(num);
	for (int i = 0; i < num; i = i + 1) {
		std::cin >> v[i];
	}
	bool find = false;
	int i = num - 1;
	while (i >= 0 && v[i] != nacion) {
		i = i - 1;
	}
	if (v[i] != nacion) {
		std::cout << (num - i) << '\n';
	}
	else {
		std::cout << "NUNCA" << '\n';
	}
	
}

bool resuelveCaso() {
	int num;
	std::cin >> num;
	std::string nacion;
	if (num == 0) {
		return false;
	}
	else {
		std::cin >> nacion;
		resolver(num, nacion);
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

