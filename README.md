# Proyecto de Ordenamiento de Nadadores

Este proyecto tiene como objetivo desarrollar un sistema para ordenar los tiempos de nadadores en diferentes pruebas utilizando algoritmos eficientes de ordenamiento. El programa lee los datos de nadadores desde un archivo de texto, los ordena por tiempos, y genera un reporte mostrando los resultados.

## Características del proyecto

- **Lectura de datos** desde un archivo de texto con información de los nadadores, como nombre, estilo, prueba, y tiempo.
- **Ordenamiento** de los nadadores en función de sus tiempos utilizando el algoritmo de ordenamiento de la STL de C++.
- **Generación de reportes** de los nadadores ordenados, exportando los resultados a un archivo de texto.
- **Pruebas automáticas** para validar que el sistema de ordenamiento funcione correctamente.

## Archivos principales

- `nadadores.h`: Define la clase `Nadador`, que incluye atributos como nombre, estilo, prueba y tiempo. También sobrecarga el operador `<` para permitir el ordenamiento por tiempo.
- `calculadora_de_tiempos.cpp`: Carga los datos de nadadores, los ordena por tiempos, y muestra los resultados.
- `reporte.h`: Genera un reporte con los nadadores ordenados en un archivo de salida.
- `pruebas.cpp`: Realiza pruebas automáticas para verificar el correcto funcionamiento del algoritmo de ordenamiento.
- `swimmers.txt`: Archivo de texto de entrada que contiene los datos de los nadadores.

## Competencias cubiertas en el proyecto

### SICT0301: Evalúa los componentes
Esta competencia refiere a la capacidad de **analizar la complejidad de los algoritmos de ordenamiento** utilizados en el programa. En este proyecto:

- El algoritmo de ordenamiento utilizado es `sort()` de la STL de C++, que combina varios algoritmos eficientes (*introsort*, *quicksort*, *heapsort*). El análisis de complejidad temporal es de **O(n log n)** en promedio, lo que es efectivo la mayoría de los problemas de ordenamiento.

### SICT0302: Toma decisiones
Esta competencia refiere a la **selección adecuada del algoritmo de ordenamiento** para resolver el problema específico de ordenar los tiempos de los nadadores. En este proyecto:

- Se ha evaluado el tipo de datos y la cantidad de entradas, seleccionando `sort()` como la mejor opción para ordenar eficientemente los tiempos.
- Las pruebas aseguran que el algoritmo cumple con los requisitos del proyecto, ordenando los tiempos de manera ascendente 

