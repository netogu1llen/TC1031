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
3. **Ordenamiento por Tiempo**: Al generar el reporte, los nadadores se ordenan por su tiempo utilizando el algoritmo Merge Sort, mejorando la utilidad del informe.
4. **Código Modularizado**: Las funciones están organizadas en dos archivos (`main.cpp` para la lógica del programa y `nadadores.h` para la implementación de la clase y funciones relacionadas).

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

```bash
g++ -std=c++11 main.cpp -o main
```

### Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

```bash
./main
```
### Descripción de las entradas del avance de proyecto
El programa requiere la entrada de datos para cada nadador, que incluye:

Nombre
Estilo
Prueba
Tiempo

El usuario proporciona estos datos manualmente a través del menú interactivo.

### Descripción de las salidas del avance de proyecto
El programa genera un archivo reporte_nadadores.txt, que contiene un listado de los nadadores procesados, mostrando su nombre, estilo, prueba y tiempo, ordenados por el tiempo de nado.

# Desarrollo de competencias

#### SICT0301: Evalúa los componentes
- Análisis de Complejidad Completo:

- Agregar Nadador: La operación push en la cola tiene una complejidad de O(1).

- Cargar Nadadores desde el Archivo: Leer y agregar cada nadador a la cola tiene una complejidad de O(n), donde n es el número de líneas en swimmers.txt.
	- Uso de una Cola (FIFO) en lugar de otras estructuras de datos 

	- Orden de llegada (FIFO):
	La cola asegura que los nadadores sean procesados en el mismo orden en que fueron ingresados, siguiendo el principio First In, First Out (FIFO).

	Este orden es esencial en situaciones donde se debe respetar la secuencia de ingreso, como en el registro y consulta de información.

	- Simplicidad y rendimiento:
	Las operaciones básicas de una cola, como agregar (O(1)) y eliminar (O(1)), son mayormente eficientes en comparación con estructuras más complejas como listas enlazadas o vectores, que pueden implicar costos adicionales. 
	- Operaciones optimizadas:
	La cola simplifica el manejo de datos secuenciales y evita la sobrecarga de operaciones más complicadas.

- Ordenamiento para el Reporte: La función `merge` (Merge Sort) tiene una complejidad de O(n log n) al ordenar los nadadores por tiempo.
	- Uso de Merge Sort en lugar de otros algoritmos de ordenamiento
	Eficiencia en el ordenamiento:

	Merge Sort tiene una complejidad temporal de O(n log⁡ n) , lo que lo hace ideal para manejar grandes volúmenes de datos, como una lista extensa de nadadores.

	Algoritmos como Bubble Sort (O(n^2)) y Selection Sort (O(n^2)) son más simples pero menos eficientes para conjuntos de datos grandes, ya que requieren muchas comparaciones y cambios.
	- División y conquista:
	El enfoque recursivo de Merge Sort divide el problema en partes más pequeñas,los ordena y combina eficientemente, lo que lo hace eficiente y adecuado para aplicaciones repetitivas como esta.

- Escritura de Reporte: Guardar el reporte en el archivo tiene una complejidad de O(n), donde n es el número de nadadores en el vector.

- Complejidad Total del Programa: La complejidad general del programa en la generación de un reporte es O(n log n) debido a la operación de ordenamiento.

	
#### SICT0302: Toma decisiones

- Selección de Algoritmo Adecuado:
La cola (FIFO) es la estructura correcta para este tipo de gestión de datos, facilitando la entrada y salida de nadadores en el orden en que son añadidos.

- Selección de Estructura de Datos:
La elección de una cola se basa en la necesidad de procesar los datos en el mismo orden en que fueron ingresados, lo que es esencial para la lógica del programa.

#### SICT0303: Implementa acciones científicas

- **Consulta de Información**:
    La consulta de información sobre los nadadores se realiza a través de la cola, utilizando los métodos propios de la clase `queue`. Para consultar los nadadores, se utiliza el algoritmo de **búsqueda secuencial**, que recorre la cola y busca el nadador deseado, comparando las características (como el nombre o el tiempo).

    **Métodos de la Cola Utilizados**:
    - `push()`: Para agregar nadadores a la cola.
    - `front()`: Para acceder al primer nadador de la cola y examinar sus datos.
    - `pop()`: Para eliminar el primer nadador de la cola una vez que se haya procesado.
    - `empty()`: Para verificar si la cola está vacía, asegurando que no se realicen búsquedas cuando no haya elementos.

    **Algoritmo de Búsqueda**:
    Para realizar una consulta, se recorre la cola desde el principio (utilizando `front()` para acceder a los nadadores) y se compara cada nadador con los criterios de búsqueda (por ejemplo, nombre, estilo, etc.). Si se encuentra el nadador que cumple con los criterios, se devuelve la información del nadador.

    El algoritmo utilizado es de **búsqueda secuencial**, lo cual es adecuado para este escenario en el que la cola se utiliza para gestionar los nadadores de manera FIFO (First In, First Out).


- **Mecanismos de Lectura y Escritura de Archivos**:
    La escritura de archivos en este proyecto se realiza mediante la gestión de la cola de nadadores. Para asegurar que los nadadores se almacenen correctamente en el archivo y se mantenga el orden en el que fueron ingresados, la estructura de la cola es utilizada eficientemente.

    **Escritura de los Nadadores en el Archivo**:
    - **Agregar Nadadores**: Los nadadores se agregan a la cola utilizando el método `push()`. Esta cola mantiene el orden de llegada de los nadadores, lo que es importante para el flujo FIFO (First In, First Out).
    - **Generación del Reporte**: Cuando se genera el reporte con los nadadores ordenados por tiempo, primero los nadadores se extraen de la cola mediante el método `pop()`. Luego, se almacenan en un vector o directamente en el archivo. El reporte final se escribe utilizando la función `ofstream` para guardar el listado de nadadores ordenados.
    - **Manejo de Archivos**: Para la escritura del reporte (`reporte_nadadores.txt`), se utiliza el método `ofstream` para abrir el archivo en modo de escritura. Cada nadador, después de ser procesado y ordenado, es escrito en el archivo en formato texto.

    **Secuencia de Escritura**:
    1. Los nadadores se almacenan en la cola (`push()`).
    2. Para generar el reporte, los nadadores son extraídos de la cola utilizando `front()` y `pop()`.
    3. Los nadadores se procesan (se ordenan por tiempo) y se escriben en el archivo de salida (`reporte_nadadores.txt`).
    
    Esto asegura que los nadadores sean procesados en el orden de llegada (FIFO) para las operaciones que lo requieran, y el reporte final se muestra en este orden. 
