#ifndef NADADORES_H
#define NADADORES_H

#include <string>
#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//Clase que representa a un nadador
class Nadador {
public:
    string nombre;
    string estilo;
    string prueba;
    double tiempo;

    //Constructor por defecto
    Nadador() : nombre(""), estilo(""), prueba(""), tiempo(0.0) {}

    //Constructor
    Nadador(string _nombre, string _estilo, string _prueba, double _tiempo)
        : nombre(_nombre), estilo(_estilo), prueba(_prueba), tiempo(_tiempo) {}

    //Sobrecarga del operador << para imprimir
    friend ostream& operator<<(ostream& os, const Nadador& nadador) {
        os << "Nombre: " << nadador.nombre 
           << ", Estilo: " << nadador.estilo 
           << ", Prueba: " << nadador.prueba 
           << ", Tiempo: " << nadador.tiempo << " segundos";
        return os;
    }
};

//Función para cargar nadadores desde el archivo
void cargarNadadoresDesdeArchivo(queue<Nadador>& nadadores, const string& file) {
    ifstream archivo(file);  //Abrir el archivo
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para cargar nadadores." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {  //Leer cada LINEA del archivo
        //Encontrar las posiciones de las comas
        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);
        size_t pos3 = linea.find(',', pos2 + 1);

        //Extraer cada componente usando substr
        string nombre = linea.substr(0, pos1);
        string estilo = linea.substr(pos1 + 1, pos2 - pos1 - 1);
        string prueba = linea.substr(pos2 + 1, pos3 - pos2 - 1);
        double tiempo = stod(linea.substr(pos3 + 1)); //Convertir la parte del tiempo a double

        //Eliminar espacios en blanco 
        nombre.erase(0, nombre.find_first_not_of(' '));
        estilo.erase(0, estilo.find_first_not_of(' '));
        prueba.erase(0, prueba.find_first_not_of(' '));

        nadadores.push(Nadador(nombre, estilo, prueba, tiempo)); //Agregar a la cola
    }

    archivo.close();//Cerrar el archivo
}

//Función para agregar un nadador a la cola 
void agregarNadador(queue<Nadador>& nadadores) {
    string nombre, estilo, prueba;
    double tiempo;

    cout << "Ingrese el nombre del nadador: ";
    cin >> nombre;
    cout << "Ingrese el estilo de nado: ";
    cin >> estilo;
    cout << "Ingrese la prueba: ";
    cin >> prueba;
    cout << "Ingrese el tiempo: ";
    cin >> tiempo;

    Nadador nuevoNadador(nombre, estilo, prueba, tiempo);
    nadadores.push(nuevoNadador); //Agregar a la cola

    //Guardar el nuevo nadador swimmers.txt
    ofstream archivo("swimmers.txt", ios::app); //Abrir el arcvhivo
    if (archivo.is_open()) {
        archivo << nombre << ", " << estilo << ", " << prueba << ", " << tiempo << endl;
        archivo.close();
        cout << "Nadador agregado exitosamente y guardado en swimmers.txt.\n";
    } else {
        cerr << "Error al abrir el archivo swimmers.txt para guardar el nadador." << endl;
    }
}

//Función para procesar y generar un reporte
void procesarNadadores(queue<Nadador>& nadadores, const string& nombreArchivo) {
    vector<Nadador> nadadoresVector; //Vector para almacenar los nadadores

    //Copiar nadadores de la cola al vector
    while (!nadadores.empty()) {
        nadadoresVector.push_back(nadadores.front());
        nadadores.pop();
    }

    //Ordenar los nadadores por tiempo
    sort(nadadoresVector.begin(), nadadoresVector.end(), [](const Nadador& a, const Nadador& b) {
        return a.tiempo < b.tiempo; //Comparar por tiempo
    });

    //Generar el reporte
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escribir el reporte." << endl;
        return;
    }

    archivo << "Reporte de Nadadores (ordenados por tiempo):\n";
    for (const auto& nadador : nadadoresVector) {
        archivo << nadador << endl; //Usar la sobrecarga de "<<"
    }

    archivo.close();
    cout << "Reporte generado exitosamente en " << nombreArchivo << endl;
}

#endif //NADADORES_H
