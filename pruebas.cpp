#include "nadadores.h"
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

//función auxiliar para eliminar espacios en blanco al inicio y al final de una cadena
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

//Función para cargar nadadores desde el archivo .txt
void cargarNadadores(vector<Nadador>& nadadores, const string& file) {
    ifstream archivo(file);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);
        size_t pos3 = linea.find(',', pos2 + 1);

        string nombre = trim(linea.substr(0, pos1));
        string estilo = trim(linea.substr(pos1 + 1, pos2 - pos1 - 1));
        string prueba = trim(linea.substr(pos2 + 1, pos3 - pos2 - 1));
        double tiempo = stod(trim(linea.substr(pos3 + 1)));

        nadadores.push_back(Nadador(nombre, estilo, prueba, tiempo));
    }

    archivo.close();
}


//Función de prueba para verificar que los nadadores se ordenan correctamente
void pruebaOrdenamiento() {
    vector<Nadador> nadadores;

    //Cargar los nadadores desde el archivo swimmers.txt
    cargarNadadores(nadadores, "swimmers.txt");

    //Ordenar nadadores por mejores tiempos
    sort(nadadores.begin(), nadadores.end());

    //Comprobar que el orden es ascendente para todos los nadadores
    for (size_t i = 1; i < nadadores.size(); ++i) {
        assert(nadadores[i - 1].tiempo <= nadadores[i].tiempo);
    }

    cout << "Prueba de ordenamiento completada correctamente." << endl;
}

int main() {
    pruebaOrdenamiento();
    return 0;
}
