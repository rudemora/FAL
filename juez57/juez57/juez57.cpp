// juez57.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <fstream>

void mostrar(std::vector<char>& v){
    for (char i : v) {
        std::cout << i;
    }
    std::cout << "\n";
}
void variacion(std::vector<char>& v, int k, int m, int n) {
    for (char i = 'a'; i < 'a' + m; i = i + 1) {
        v[k] = i;
        if (k == n - 1) {
            mostrar(v);
        }
        else {
            variacion(v, k + 1, m, n);
        }
    }
}

bool resuelveCaso() {
    int m;
    std::cin >> m;
    if (!std::cin) {
        return false;
    }
    else {
        int n;
        std::cin >> n;
        std::vector<char> v(n);
        variacion(v, 0, m, n);
        std::cout << "\n";
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
