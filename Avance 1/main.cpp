#include <iostream>
#include <queue>
#include "nadadores.h" //Clase & funciones

using namespace std;

int main() {
    queue<Nadador> nadadores; //Cola para almacenar los nadadores
    cargarNadadoresDesdeArchivo(nadadores, "swimmers.txt"); //Cargar nadadores 
    int opcion; //Variable para almacenar la selección

    do {
        cout << "\nMenu de Opciones:\n";
        cout << "1. Agregar nadador\n";
        cout << "2. Generar reporte\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarNadador(nadadores); //Agregar un nuevo nadador
                break;

            case 2:
                procesarNadadores(nadadores, "reporte_nadadores.txt"); //Generar el reporte
                break;

            case 3:
                cout << "Saliendo del programa.\n"; //Salir del programa
                break;

            default:
                cout << "Opcion invalida. Por favor, intente de nuevo.\n"; //opcion no vsalida
                break;
        }
    } while (opcion != 3); //continuar hasta que decida salir

    return 0; 
}
