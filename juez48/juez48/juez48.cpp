// juez48.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>

using namespace std;

void resolver(vector<int>& v, bool& exito, int ini, int fin, int& max, int& min) {
    if (ini + 1 >= fin) {
        exito = false;
    }
    else {
        if (v[ini] <)
    }
}

bool resuelveCaso() {
    int num;
    cin >> num;
    if (!cin) {
        return false;
    }
    vector<int> v(num);
    for (int i = 0; i < num; i++) {
        cin >> v[i];
    }
    bool exito = false;
    int max = 0;
    int min = 0;
    resolver(v, exito, 0, v.size() - 1, min, max);
    if (exito) {
        cout << "SIEMPRE PREMIO\n";
    }
    else {
        cout << "ELEGIR OTRA\n";
    }
    return true;
}

int main()
{
    while (resuelveCaso());
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
