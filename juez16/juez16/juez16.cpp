// juez16.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

# include <iostream>
# include <fstream>
# include <vector>

struct tSol {
    int ganados;
    int veces;
    int ultimosPerdidos;
};
tSol resolver(std::vector <int > & v) {
    int longmax = 0; 
    int ultmax = -1; 
    int numveces = 0; 
    int longitud = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > 0) {
            ++longitud;
            if (longmax < longitud) {
                longmax = longitud;
                ultmax = i;
                numveces = 1;
            }
            else if (longmax == longitud) {
                ++numveces;
                ultmax = i;
            }
        }
        else longitud = 0;
    }
    return { longmax , numveces , (int)v.size() - ultmax - 1 };
}
bool resuelveCaso() {
    int num;
    std::cin >> num;
    if (!std::cin) {
        return false;
    }
    else {
        std::vector <int > v(num);
        for (int i = 0; i < num; ++i) {
            std::cin >> v[i];
        }
        tSol sol = resolver(v);
        std::cout << sol.ganados << ' ' << sol.veces << ' ' << sol.ultimosPerdidos << '\n';
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

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
