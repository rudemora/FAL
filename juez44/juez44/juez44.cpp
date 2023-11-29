// juez44.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

int suma(std::vector<int>& v, int ini, int fin) {
    int sol = 0;
    for (int i = ini; i < fin; i = i + 1) {
        sol = sol + v[i];
    }
    return sol;
}

bool resolver(std::vector<int>& v, int ini, int fin) {
    if (ini + 1 == fin) {
        return true;
    }
    else {
        int medio = (ini + fin) / 2;
        if (suma(v, ini, medio) < suma(v, medio, fin)) {
            return resolver(v, ini, medio) && resolver(v, medio, fin);
        }
        else {
            return false;
        }
    }
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!std::cin) {
        return false;
    }
    else {
        int m;
        std::cin >> m;
        std::vector<int> v(m);
        bool solucion = true;
        for (int i = 0; i < n; i = i + 1) {
            for (int j = 0; j < m; j = j + 1) {
                std::cin >> v[j];
            }
            bool sol = resolver(v, 0, m);
            if (!sol) {
                solucion = false;
            }
        }
        if (solucion) {
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
