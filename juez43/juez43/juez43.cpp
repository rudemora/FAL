// juez43.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

bool resolver(std::vector<int>& v, int k, int ini, int fin) {
    if (ini + 1 == fin) {
        return true;
    }
    else if (ini + 2 >= fin) {
        if (abs(v[ini] - v[ini + 1]) >= k) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if (abs(v[ini] - v[fin - 1]) >= k) {
            int medio = (ini + fin) / 2;
            return resolver(v, k, ini, medio) && resolver(v, k, medio, fin);
        }
        else {
            return false;
        }
    }
}

bool resuelveCaso() {
    int longitud;
    std::cin >> longitud;
    if (!std::cin) {
        return false;
    }
    else {
        int k;
        std::cin >> k;
        std::vector<int> v(longitud);
        for (int i = 0; i < longitud; i = i + 1) {
            std::cin >> v[i];
        }
        bool sol = resolver(v, k, 0, longitud);
        if (sol) {
            std::cout << "SI\n";
        }
        else {
            std::cout << "NO\n";
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
