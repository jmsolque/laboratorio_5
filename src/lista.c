#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Inserta un valor al inicio de la lista
void insertar_inicio(Nodo **lista, int valor) {
    // Validación simple
    if (lista == NULL) {
        printf("Error: lista no inicializada\n");
        return;
    }

    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (!nuevo) {
        printf("Error al asignar memoria\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->siguiente = *lista;

    *lista = nuevo;
}

// Imprime todos los valores de la lista
void imprimir_lista(Nodo *lista) {
    Nodo *actual = lista;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Libera la memoria de la lista
void liberar_lista(Nodo **lista) {
    Nodo *actual = *lista;
    Nodo *tmp;

    while (actual != NULL) {
        tmp = actual;
        actual = actual->siguiente;
        free(tmp);
    }

    *lista = NULL;
}
