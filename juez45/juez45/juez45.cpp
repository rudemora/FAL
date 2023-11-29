// juez45.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

struct tJug {
    std::string nombre;
    int canicas; 
};

tJug resolver(std::vector<tJug>& v, int ini, int fin) {
    if (ini + 1 == fin) {
        return v[ini];
    }
    else if (ini + 2 == fin) {
        if (v[ini].canicas >= v[ini + 1].canicas) {
            v[ini].canicas += v[ini + 1].canicas/2;
            return v[ini];
        }
        else {
            v[ini + 1].canicas += v[ini].canicas/2;
            return v[ini + 1];
        }
    }
    else {
        int medio = (ini + fin) / 2;
        tJug ganIz = resolver(v, ini, medio);
        tJug ganDr = resolver(v, medio, fin);
        if (ganIz.canicas >= ganDr.canicas) {
            ganIz.canicas += ganDr.canicas / 2;
            return ganIz;
        }
        else {
            ganDr.canicas += ganIz.canicas / 2;
            return ganDr;
        }
    }
}

bool resuelveCaso() {
    int num;
    std::cin >> num;
    if (!std::cin) {
        return false;
    }
    else {
        std::vector<tJug> v(num);
        for (int i = 0; i < num; i = i + 1) {
            std::cin >> v[i].nombre;
            std::cin >> v[i].canicas;
        }
        tJug sol = resolver(v, 0, v.size());
        std::cout << sol.nombre << " " << sol.canicas << "\n";
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
