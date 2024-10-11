# Proyecto de Ordenamiento de Nadadores

Este proyecto tiene como objetivo desarrollar un sistema para ordenar los tiempos de nadadores en diferentes pruebas utilizando algoritmos eficientes de ordenamiento. El programa lee los datos de nadadores desde un archivo de texto, los ordena por tiempos, y genera un reporte mostrando los resultados.

## Características del proyecto

- **Lectura de datos** desde un archivo de texto con información de los nadadores, como nombre, estilo, prueba, y tiempo.
- **Ordenamiento** de los nadadores en función de sus tiempos utilizando el algoritmo de ordenamiento de la STL de C++.
- **Generación de reportes** de los nadadores ordenados, exportando los resultados a un archivo de texto.
- **Pruebas automáticas** para validar que el sistema de ordenamiento funcione correctamente.

## Archivos principales

- `main.cpp`: Contiene la implementación principal del programa. Carga los datos de nadadores, los ordena por tiempos, filtra por estilo y genera archivos de salida.
- `nadadores.h`: Define la clase `Nadador`, que incluye atributos como nombre, estilo, prueba y tiempo. También sobrecarga el operador `<` para permitir el ordenamiento por tiempo.
- `swimmers.txt`: Archivo de texto de entrada que contiene los datos de los nadadores.
- `reporte_nadadores.txt`: Archivo de salida que se genera con el reporte de los nadadores ordenados por tiempo.
- `nadadores_por_estilo.txt`: Archivo de salida que se genera con los nadadores filtrados por estilo.


## Competencias cubiertas en el proyecto

### SICT0301: Evalúa los componentes
Esta competencia refiere a la capacidad de **analizar la complejidad de los algoritmos de ordenamiento** utilizados en el programa. En este proyecto:

- **Análisis de complejidad**:
  - El algoritmo de ordenamiento utilizado es `sort()` de la STL de C++, que combina varios algoritmos eficientes (*introsort*, *quicksort*, *heapsort*). 
  - La complejidad temporal de `sort()` es de **O(n log n)** en promedio, lo que es efectivo para la mayoría de los problemas de ordenamiento.
  - La función `cargarNadadores` tiene una complejidad de **O(n)**, donde n es el número de nadadores en el archivo. Esto se debe a que lee cada línea del archivo una vez.

### SICT0302: Toma decisiones
Esta competencia refiere a la **selección adecuada del algoritmo de ordenamiento** para resolver el problema específico de ordenar los tiempos de los nadadores. En este proyecto:

- **Selección del algoritmo**:
  - Se ha evaluado el tipo de datos y la cantidad de entradas, seleccionando `sort()` como la mejor opción para ordenar eficientemente los tiempos.
  - Se utiliza un `vector<Nadador>` para almacenar los datos, lo cual es apropiado porque permite un acceso dinámico y fácil ordenación.
  - El uso de clases y objetos para encapsular la información del nadador permite una buena organización y gestión de los datos.

### SICT0303: Implementa acciones científicas 
Esta competencia se refiere a la **implementación de mecanismos de lectura y escritura de archivos**:

- **Consulta de información**:
  - La función `escribirNadadores` permite consultar la información de los nadadores de forma clara y concisa, escribiendo los resultados en un archivo en lugar de imprimirlos en consola.

- **Carga de archivos**:
  - La función `cargarNadadores` implementa un mecanismo eficaz para leer los datos desde un archivo `.txt`, asegurando que los datos se carguen correctamente en la estructura de datos.
  
- **Escritura de archivos**:
  - La función `escribirNadadoresPorEstilo` y `generarReporte` escriben la información de los nadadores en archivos de salida, facilitando la consulta y almacenamiento de los resultados.
