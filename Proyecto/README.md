# Proyecto: Gestión de Nadadores con Cola

## Descripción
Este proyecto permite gestionar información sobre nadadores utilizando una estructura de datos en forma de cola (FIFO). El programa permite agregar nadadores, procesar sus datos y generar reportes de manera sencilla y eficiente. Al generar el reporte, los nadadores son ordenados por sus tiempos.

## Descripción del avance 1
En la primera versión del proyecto, se implementó una gestión básica de nadadores utilizando un vector. Se podían cargar, ordenar y generar reportes, pero la estructura no facilitaba el manejo ordenado de los nadadores según el orden de ingreso.

## Descripción del avance 2
En esta segunda versión, el enfoque se ha cambiado a utilizar una cola para gestionar los nadadores. Esto permite que los nadadores sean procesados en el orden en que son ingresados, facilitando la generación de reportes y mejorando la usabilidad del programa.

### Cambios sobre el primer avance
1. **Uso de Cola**: Se ha implementado una cola para manejar los nadadores, lo que permite un procesamiento FIFO.
2. **Funciones de Interacción**: Se han añadido funciones específicas para agregar nadadores y generar reportes, simplificando la interacción del usuario.
3. **Ordenamiento por Tiempo**: Al generar el reporte, los nadadores se ordenan por su tiempo, mejorando la utilidad del informe.
4. **Código Modularizado**: Las funciones están organizadas en dos archivos (`main.cpp` para la lógica del programa y `nadadores.h` para la implementación de la clase y funciones relacionadas).

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

```bash
g++ main.cpp -o gestion_nadadores
```

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

```bash
./gestion_nadadores
```

## Descripción de las entradas del avance de proyecto
El programa requiere la entrada de datos para cada nadador, que incluye:
- Nombre
- Estilo
- Prueba
- Tiempo

El usuario proporciona estos datos manualmente a través del menú interactivo.

## Descripción de las salidas del avance de proyecto
El programa genera un archivo `reporte_nadadores.txt`, que contiene un listado de los nadadores procesados, mostrando su nombre, estilo, prueba y tiempo, ordenados por el tiempo de nado.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
- **Análisis de Complejidad Completo**:
  - **Agregar Nadador**: La operación `push` en la cola tiene una complejidad de O(1).
  - **Cargar Nadadores desde el Archivo**: Leer y agregar cada nadador a la cola tiene una complejidad de O(n), donde *n* es el número de líneas en `swimmers.txt`.
  - **Ordenamiento para el Reporte**: La función `sort` tiene una complejidad de O(n log n) al ordenar los nadadores por tiempo.
  - **Escritura de Reporte**: Guardar el reporte en el archivo tiene una complejidad de O(n), donde *n* es el número de nadadores en el vector.
  - **Complejidad Total del Programa**: La complejidad general del programa en la generación de un reporte es O(n log n) debido a la operación de ordenamiento, siendo el paso dominante en términos de complejidad.

### SICT0302: Toma decisiones
- **Selección de Algoritmo Adecuado**: 
  - La cola (FIFO) es la estructura correcta para este tipo de gestión de datos, facilitando la entrada y salida de nadadores en el orden en que son añadidos.
- **Selección de Estructura de Datos**: 
  - La elección de una cola se basa en la necesidad de procesar los datos en el mismo orden en que fueron ingresados, lo que es esencial para la lógica del programa.

### SICT0303: Implementa acciones científicas
- **Consulta de Información**: 
  - Se implementan mecanismos para consultar la información de los nadadores a través del menú, lo que mejora la interacción con el usuario.
  
- **Mecanismos de Lectura y Escritura de Archivos**: 
  - La función `cargarNadadoresDesdeArchivo` carga los nadadores de `swimmers.txt` y los almacena en la cola. La función `procesarNadadores` escribe un archivo `reporte_nadadores.txt` que contiene el reporte de los nadadores ordenados por tiempo. Estos mecanismos garantizan que los datos se gestionen de manera eficiente y precisa.
