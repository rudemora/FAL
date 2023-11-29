// juez38.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

int resolver(std::vector<int> v, int inicio, int final, int primero) {
    if (inicio + 1 >= final) {
        if (v[inicio] != 1 && primero == v.size()+1) {
            return 0;
        }
        else {
            if (v[inicio] == 1) {
                return (v.size()-inicio);
            }
            else if (primero > v.size()) {
                return (v.size()-1);
            }
            else {
                return (v.size() - primero);
            }
            
        }
    }
    else {
        int medio = (inicio + final - 1) / 2;
        if (v[medio] == 1 && medio < primero ) {
            return resolver(v, inicio, medio, medio);
        }
        else {
            return resolver(v, medio + 1, final, primero);
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
        std::vector<int> v(num);
        for(int i = 0; i < num; i = i + 1) {
            std::cin >> v[i];
        }
        int inicio = resolver(v, 0, num, num + 1);
        std::cout << inicio << "\n";
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
