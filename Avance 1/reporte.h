#ifndef REPORTE_H
#define REPORTE_H

#include <vector>
#include <fstream>
#include <iostream>  // Necesario para usar cerr y endl
#include "nadadores.h"

using namespace std;  // Esto te permite usar cerr, cout y otros elementos estándar de C++ sin std::

void generarReporte(const vector<Nadador>& nadadores, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de reporte." << endl;
        return;
    }

    archivo << "Nadadores ordenados por mejores tiempos:\n";
    for (const auto& nadador : nadadores) {
        archivo << "Nombre: " << nadador.nombre 
                << ", Estilo: " << nadador.estilo 
                << ", Prueba: " << nadador.prueba << " metros"
                << ", Tiempo: " << nadador.tiempo << " segundos\n";
    }

    archivo.close();
}

#endif
