#ifndef NADADORES_H
#define NADADORES_H
using namespace std;

#include <string>

class Nadador {
public:
    string nombre;
    string estilo;
    string prueba;
    double tiempo;

    //Constructor modificado para incluir el estilo
    Nadador(string _nombre, string _estilo, string _prueba, double _tiempo)
        : nombre(_nombre), estilo(_estilo), prueba(_prueba), tiempo(_tiempo) {}

    //Sobrecarga del operador < para ordenar por mejores tiempos
    bool operator<(const Nadador& other) const {
        return tiempo < other.tiempo;
    }
};
#endif
