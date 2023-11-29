// juez50.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct tSol {
    int ronda;
    int partidos;
    bool jugado;
};

tSol resolver(std::vector<std::string>& v, int ronda, int ini, int fin) {
    tSol sol;
    if (ini + 2 == fin) {
        if (v[ini] == "NP" && v[fin - 1] == "NP") {
            sol.partidos = 0;
            sol.jugado = false;
            sol.ronda = 1;
            return sol;
        }
        else {
            if (v[ini] == "NP") {
                sol.ronda = 1;
                sol.jugado = true;
                sol.partidos = 0;
                return sol;
            }
            if (v[fin - 1] == "NP") {
                sol.ronda = 1;
                sol.jugado = true;
                sol.partidos = 0;
                return sol;
            }
            else {
                sol.jugado = true;
                sol.partidos = 1;
                sol.ronda = 1;
                return sol;
            }
        }
    }
    else {
        int mitad = (ini + fin - 1) / 2;
        tSol solIz = resolver(v, ronda, ini, mitad + 1 );
        tSol solDr = resolver(v, ronda, mitad + 1, fin);
        sol.ronda = solIz.ronda + 1;
        sol.partidos = solIz.partidos + solDr.partidos;
        sol.jugado = solIz.jugado || solDr.jugado;
        if (sol.ronda <= ronda) {
            if (solIz.jugado && solDr.jugado) {
                sol.partidos = sol.partidos + 1;
                return sol;
            }
            else {
                return sol;
            }
            
        }
        else {
            return sol;
        }
    }
}

bool resuelveCaso() {
    int numJ;
    std::cin >> numJ;
    int ronda;
    std::cin >> ronda;
    if (!std::cin) {
        return false;
    }
    else {
        std::vector<std::string> v(numJ);
        for (int i = 0; i < numJ; i = i + 1) {
            std::cin >> v[i];
        }
        tSol sol = resolver(v, ronda, 0, v.size());
        std::cout << sol.partidos << "\n";
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
