#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>

/* Ejercicio 1: Crear un nodo usando malloc */
Nodo* crearNodo(int valor){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
    }
    return nuevo;
}

/* Ejercicio 2: Crear arreglo continuo de nodos usando calloc */
Nodo* crearArregloNodos(int n){
    // calloc inicializa la memoria en 0 (dato = 0, siguiente = NULL)
    Nodo* arreglo = (Nodo*)calloc(n, sizeof(Nodo));
    return arreglo;
}

/* Ejercicio 3: Agregar un nodo redimensionando el arreglo continuo */
Nodo* agregarNodo(Nodo* arreglo, int* n, int valor){
    Nodo* nuevoArreglo = (Nodo*)realloc(arreglo, (*n + 1) * sizeof(Nodo));
    if (nuevoArreglo != NULL) {
        nuevoArreglo[*n].dato = valor;
        nuevoArreglo[*n].siguiente = NULL;
        (*n)++; // Incrementamos el tamaño total
    }
    return nuevoArreglo;
}

/* Ejercicio 4: Liberar memoria dinámica */
void liberarNodos(Nodo* arreglo, int n){
    // Ya sea un solo nodo creado con malloc o un arreglo de realloc/calloc, 
    // se libera todo el bloque contiguo con un solo free.
    if (arreglo != NULL) {
        free(arreglo);
    }
}

/* Ejercicio 5: Crear y enlazar 3 nodos manualmente */
Nodo* construirTresNodos(){
    Nodo* n1 = crearNodo(100);
    Nodo* n2 = crearNodo(200);
    Nodo* n3 = crearNodo(300);

    if (n1 && n2 && n3) {
        n1->siguiente = n2;
        n2->siguiente = n3;
    }
    
    return n1; // Retornamos el inicio de la lista
}

/* Ejercicio 6: Contar los elementos de una lista enlazada */
int contarNodos(Nodo* inicio){
    int contador = 0;
    Nodo* actual = inicio;
    
    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    
    return contador;
}

/* Ejercicio 7: Crear lista enlazada por entradas hasta ingresar -1 */
Nodo* crearNodosPorEntrada(){
    Nodo* inicio = NULL;
    Nodo* ultimo = NULL;
    int valor;

    printf("Ingresa numeros enteros para la lista (-1 para terminar): ");
    while (scanf("%d", &valor) == 1 && valor != -1) {
        Nodo* nuevo = crearNodo(valor);
        if (inicio == NULL) {
            inicio = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }
    return inicio;
}




