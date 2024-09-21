#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "nadadores.h"

using namespace std;

//cargar nadadores desde el .txt
void cargarNadadores(vector<Nadador>& nadadores, const string& file) {
    ifstream archivo(file);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    string linea, nombre, estilo, prueba;
    double tiempo;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        getline(ss, nombre, ',');
        getline(ss, estilo, ',');
        getline(ss, prueba, ',');
        ss >> tiempo;

        // Eliminar espacios en blanco adicionales si es necesario
        nombre.erase(0, nombre.find_first_not_of(' '));
        estilo.erase(0, estilo.find_first_not_of(' '));
        prueba.erase(0, prueba.find_first_not_of(' '));

        nadadores.push_back(Nadador(nombre, estilo, prueba, tiempo));
    }

    archivo.close();
}

//mostrar los nadadores ordenados por mejor tiempo
void mostrarNadadores(const vector<Nadador>& nadadores) {
    for (const auto& nadador : nadadores) {
        cout << "Nombre: " << nadador.nombre 
             << ", Estilo: " << nadador.estilo 
             << ", Prueba: " << nadador.prueba 
             << ", Tiempo: " << nadador.tiempo << " segundos" << endl;
    }
}

int main() {
    vector<Nadador> nadadores;
    cargarNadadores(nadadores, "swimmers.txt");

    // Ordenar nadadores por mejores tiempos
    sort(nadadores.begin(), nadadores.end());

    // Mostrar los nadadores ordenados
    cout << "Nadadores ordenados por mejores tiempos:" << endl;
    mostrarNadadores(nadadores);

    return 0;
}
