
// juez25.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

void resolver(std::vector<int>& v, int longitud) {
    int primer_desn = 0;
    int segundo_desn = 0;
    int suma = v[0];
    int sumamax;
    for (int i = 1; i < longitud; i = i + 1) {
        suma = suma + v[i];
    }
    sumamax = suma;
    primer_desn = 0;
    for (int i = longitud; i < v.size(); i = i + 1) {
        suma = suma - v[i - longitud];
        suma = suma + v[i];
        if (suma > sumamax) {
            sumamax = suma;
            segundo_desn = i - longitud + 1;
            primer_desn = segundo_desn;
        }
        else if (suma == sumamax) {
            segundo_desn = i - longitud + 1;
        }
    }
    std::cout << sumamax << " " << primer_desn << " " << segundo_desn << "\n";
}

bool resuelveCaso() {
    int num;
    int longitud;
    std::cin >> num >> longitud;
    if (num == 0 && longitud == 0) {
        return false;
    }
    else {
        std::vector<int> v(num);
        for (int i = 0; i < num; i = i + 1) {
            std::cin >> v[i];
        }
        resolver(v, longitud);
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
