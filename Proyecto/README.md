# Proyecto: Gestión de Nadadores con Cola

## Descripción
Este proyecto permite gestionar información sobre nadadores utilizando una estructura de datos en forma de cola (FIFO). El programa permite agregar nadadores, procesar sus datos y generar reportes de manera sencilla y eficiente.

## Descripción del avance 1
En la primera versión del proyecto, se implementó una gestión básica de nadadores utilizando un vector. Se podían cargar, ordenar y generar reportes, pero la estructura no facilitaba el manejo ordenado de los nadadores según el orden de ingreso.

## Descripción del avance 2
En esta segunda versión, el enfoque se ha cambiado a utilizar una cola para gestionar los nadadores. Esto permite que los nadadores sean procesados en el orden en que son ingresados, facilitando la generación de reportes y mejorando la usabilidad del programa.

### Cambios sobre el primer avance
1. **Uso de Cola**: Se ha implementado una cola para manejar los nadadores, lo que permite un procesamiento FIFO.
2. **Funciones de Interacción**: Se han añadido funciones específicas para agregar nadadores y generar reportes, simplificando la interacción del usuario.
3. **Código Consolidado**: Se ha separado la funcionalidad en dos archivos, `main.cpp` para la lógica del programa y `queue.h` para la implementación de la cola.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

```bash
g++ main.cpp -o gestion_nadadores
