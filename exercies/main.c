#include "nodo.h"
#include <stdio.h>

// Función auxiliar para imprimir listas enlazadas
void imprimirLista(Nodo* inicio) {
    Nodo* temp = inicio;
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

int main() {
    printf("===== Repo de ejercicios de nodos =====\n\n");

    // Ejercicio 1
    Nodo* n1 = crearNodo(10);
    if (n1) printf("[Ej 1] Nodo individual creado con dato: %d\n", n1->dato);

    // Ejercicio 2
    Nodo* arreglo = crearArregloNodos(5);
    // TODO(1): imprimir arreglo
    if (arreglo) {
        printf("[Ej 2] Arreglo inicial de %d elementos (calloc): ", 5);
        for (int i = 0; i < 5; i++) {
            printf("%d ", arreglo[i].dato);
        }
        printf("\n");
    }

    // Ejercicio 3
    int tam = 5;
    arreglo = agregarNodo(arreglo, &tam, 99);
    // TODO(2): imprimir arreglo actualizado
    if (arreglo) {
        printf("[Ej 3] Arreglo actualizado (tam: %d) con realloc: ", tam);
        for (int i = 0; i < tam; i++) {
            printf("%d ", arreglo[i].dato);
        }
        printf("\n");
    }

    // Ejercicio 4
    printf("[Ej 4] Liberando memoria del arreglo y el nodo n1...\n");
    liberarNodos(arreglo, tam);
    liberarNodos(n1, 1);

    // Ejercicio 5
    Nodo* inicio = construirTresNodos();
    // TODO(3): imprimir nodos
    printf("[Ej 5] Lista construida manualmente: ");
    imprimirLista(inicio);

    // Ejercicio 6
    int total = contarNodos(inicio);
    printf("[Ej 6] Total de nodos en la lista manual: %d\n", total);

    // Ejercicio 7
    Nodo* desdeEntrada = crearNodosPorEntrada();
    // TODO(4): imprimir nodos
    printf("[Ej 7] Lista leida por entrada: ");
    imprimirLista(desdeEntrada);

    return 0;
}
