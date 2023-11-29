// juez40.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

char resolver(std::vector<char>& v, char primeraL, int inicio, int fin) {
    if (v[0] != primeraL) {
    return char(v[0] - 1);
    }
    else if (v[v.size() - 1] != primeraL + v.size()) {
        return char(v[0] + v.size());
    }
    else if (inicio + 1 == fin) {
        return char(v[inicio] + 1);
    }
    
    else {
        int medio = (inicio + fin) / 2;
        if (v[medio] - v[inicio] == medio - inicio) {
            return resolver(v, primeraL, medio, fin);
        }
        else {
            return resolver(v, primeraL, inicio, medio);
        }
    }
}

void resuelveCaso() {
    char inicio;
    std::cin >> inicio;
    char final;
    std::cin >> final;
    std::vector<char> v(final - inicio);
    for (int i = 0; i < v.size(); i = i + 1) {
        std::cin >> v[i];
    }
    char sol = resolver(v, inicio, 0 , v.size());
    std::cout << sol << "\n";
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
