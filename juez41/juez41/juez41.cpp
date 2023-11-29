// juez41.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

int resolver(std::vector<int>& v, std::vector<int>& w, int ini, int fin) {
    if (v[0] != w[0]) {
        return v[0];
    }
    if (ini + 1 == fin) {
        return v[ini + 1];
    }
    else {
        int medio = (ini + fin) / 2;
        if (v[medio] - v[ini] == w[medio] - w[ini]) {
            return resolver(v, w, medio, fin);
        }
        else {
            return resolver(v, w, ini, medio);
        }
    }
}

void resuelveCaso() {
    int longitud;
    std::cin >> longitud;
    std::vector<int> v(longitud);
    for (int i = 0; i < longitud; i = i + 1) {
        std::cin >> v[i];
    }
    if (longitud == 1) {
        std::cout << v[0] << "\n";
    }
    else{
        std::vector<int> w(longitud-1);
        for (int i = 0; i < longitud - 1; i = i + 1) {
            std::cin >> w[i];
        }
        int sol = resolver(v, w, 0, longitud-1);
        std::cout << sol << "\n";
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
