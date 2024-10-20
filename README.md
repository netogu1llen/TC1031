# Proyecto: Gestión de Nadadores 

## Descripción
Este proyecto permite gestionar información sobre nadadores utilizando una estructura de datos cola, FIFO. El programa permite agregar nadadores, procesar sus datos y generar reportes. 

## Descripción del avance 1
En la primera versión del proyecto, se implementó una gestión básica de nadadores utilizando un vector. Se podían cargar desde archivos, ordenar y generar reportes, pero no permitía hacer nada más.

## Descripción del avance 2
En esta segunda versión, el enfoque se ha cambiado a utilizar una cola para gestionar los nadadores. Esto permite que los nadadores sean procesados en el orden en que son ingresados.

### Cambios sobre el primer avance
1. **Uso de Cola**: Se ha implementado una cola para manejar los nadadores, lo que permite un procesamiento FIFO.
2. **Funciones de Interacción**: Se han añadido funciones específicas para agregar nadadores y generar reportes.
3. **Ordenamiento por Tiempo**: Al generar el reporte, los nadadores se ordenan por su tiempo.
4. **Código Consolidado**: Se ha simplificado la funcionalidad en sólo dos archivos.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

g++ main.cpp -o main ó si ya compiló simplemente .\main

### Descripción de las entradas del avance de proyecto
* El programa requiere la entrada de datos para cada nadador:
Nombre
Estilo
Prueba
Tiempo
El usuario proporciona estos datos manualmente a través del menú.

### Descripción de las salidas del avance de proyecto
* El programa genera un archivo reporte_nadadores.txt, que contiene un listado de los nadadores procesados, mostrando su nombre, estilo, prueba y tiempo. Siendo ordenados por el tiempo de nado.

# Desarrollo de competencias
## SICT0301: Evalúa los componentes
* Análisis de complejidad:
    La complejidad de las operaciones de encolar y desencolar es O(1), asegurando un rendimiento eficiente al manejar los nadadores.
    La generación de reportes tiene una complejidad O(n log n) debido al uso de sort para ordenar los nadadores.

* Análisis de estructuras de datos:
La cola es una elección adecuada para este problema, ya que permite un acceso ordenado a los datos conforme son ingresados.

##SICT0302: Toma decisiones
* Selección de algoritmo adecuado:
La queque  es la estructura correcta para este tipo de gestión de datos, facilitando la entrada y salida de nadadores en el orden en que son añadidos.

* Selección de estructura de datos:
La elección de una cola se basa en la necesidad de procesar los datos en el mismo orden en que fueron ingresados, lo que es esencial para la lógica del programa.

##SICT0303: Implementa acciones científicas
* Consulta de información:
Se implementó una consulta de la información de los nadadores a través del menú, lo que mejora la interacción con el usuario.

* Lectura de archivos:
El programa permite cargar datos desde un archivo, facilitando la gestión de información sin necesidad de entrada manual repetitiva.
