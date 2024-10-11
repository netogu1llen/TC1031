#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Nadador {
public:
    string nombre;
    string estilo;
    string prueba;
    double tiempo;

    //Constructor
    Nadador(string _nombre, string _estilo, string _prueba, double _tiempo)
        : nombre(_nombre), estilo(_estilo), prueba(_prueba), tiempo(_tiempo) {}

    //Sobrecarga del operador < para ordenar por mejores tiempos
    bool operator<(const Nadador& other) const {
        return tiempo < other.tiempo;
    }
};

//Cargar los nadadores desde el archivo .txt
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

        //Eliminar espacios en blanco adicionales
        nombre.erase(0, nombre.find_first_not_of(' '));
        estilo.erase(0, estilo.find_first_not_of(' '));
        prueba.erase(0, prueba.find_first_not_of(' '));

        nadadores.push_back(Nadador(nombre, estilo, prueba, tiempo));
    }

    archivo.close();
}

//Escribir los nadadores en un archivo
void escribirNadadores(const vector<Nadador>& nadadores, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escribir." << endl;
        return;
    }

    for (const auto& nadador : nadadores) {
        archivo << "Nombre: " << nadador.nombre 
                << ", Estilo: " << nadador.estilo 
                << ", Prueba: " << nadador.prueba 
                << ", Tiempo: " << nadador.tiempo << " segundos" << endl;
    }

    archivo.close();
    cout << "Nadadores escritos exitosamente en " << nombreArchivo << endl;
}

//Filtrar nadadores por estilo y escribir en un archivo
void escribirNadadoresPorEstilo(const vector<Nadador>& nadadores, const string& estilo, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escribir." << endl;
        return;
    }

    archivo << "Nadadores que nadan estilo " << estilo << ":\n";
    for (const auto& nadador : nadadores) {
        if (nadador.estilo == estilo) {
            archivo << "Nombre: " << nadador.nombre 
                    << ", Estilo: " << nadador.estilo 
                    << ", Prueba: " << nadador.prueba 
                    << ", Tiempo: " << nadador.tiempo << " segundos" << endl;
        }
    }

    archivo.close();
    cout << "Nadadores filtrados por estilo escritos exitosamente en " << nombreArchivo << endl;
}

//Generar un reporte de los nadadores
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
                << ", Prueba: " << nadador.prueba 
                << ", Tiempo: " << nadador.tiempo << " segundos\n";
    }

    archivo.close();
    cout << "Reporte generado exitosamente en " << nombreArchivo << endl;
}

int main() {
    vector<Nadador> nadadores; //Vector para almacenar los nadadores
    int opcion; //Variable para almacenar la opción seleccionada

    do {
        cout << "\nMenu de Opciones:\n";
        cout << "1. Cargar nadadores\n";
        cout << "2. Ordenar y escribir nadadores por tiempo\n";
        cout << "3. Filtrar nadadores por estilo\n";
        cout << "4. Generar un reporte\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cargarNadadores(nadadores, "swimmers.txt"); //Cargar los nadadores
                cout << "Nadadores cargados exitosamente.\n";
                break;

            case 2:
                sort(nadadores.begin(), nadadores.end()); //Ordenar los nadadores por tiempo
                escribirNadadores(nadadores, "nadadores_ordenados.txt"); //Escribir en archivo
                break;

            case 3: {
                string estilo;
                cout << "Ingrese el estilo a filtrar: ";
                cin >> estilo;
                escribirNadadoresPorEstilo(nadadores, estilo, "nadadores_por_estilo.txt"); //Filtrar y escribir en archivo
                break;
            }

            case 4:
                generarReporte(nadadores, "reporte_nadadores.txt"); //Generar el reporte
                break;

            case 5:
                cout << "Saliendo del programa.\n"; //Salir del programa
                break;

            default:
                cout << "Opcion invalida. Por favor, intente de nuevo.\n"; //Manejo de opción no válida
                break;
        }
    } while (opcion != 5); //Continuar hasta que el usuario decida salir

    return 0; //Fin del programa
}
