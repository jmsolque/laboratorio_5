#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Crea un nodo nuevo con el valor dado
Nodo *crear_nodo(int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (!nuevo) {
        printf("Error al asignar memoria para el nodo\n");
        return NULL;
    }
    nuevo->valor = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Inserta un valor al inicio de la lista
void insertar_inicio(Nodo **lista, int valor) {
    if (lista == NULL) {
        printf("Error: lista no inicializada\n");
        return;
    }

    Nodo *nuevo = crear_nodo(valor);
    if (!nuevo) return;

    nuevo->siguiente = *lista;
    *lista = nuevo;
}

// Inserta un valor al final de la lista
void insertar_final(Nodo **lista, int valor) {
    if (lista == NULL) {
        printf("Error: lista no inicializada\n");
        return;
    }

    Nodo *nuevo = crear_nodo(valor);
    if (!nuevo) return;

    if (*lista == NULL) {
        *lista = nuevo;
        return;
    }

    Nodo *actual = *lista;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
}

// Inserta un valor en una posición (0 = inicio)
void insertar_posicion(Nodo **lista, int valor, int posicion) {
    if (lista == NULL || posicion < 0) {
        printf("Posición inválida\n");
        return;
    }

    if (posicion == 0) {
        insertar_inicio(lista, valor);
        return;
    }

    Nodo *actual = *lista;
    int i = 0;

    while (actual != NULL && i < posicion - 1) {
        actual = actual->siguiente;
        i++;
    }

    if (actual == NULL) {
        printf("Posición fuera de rango, se inserta al final\n");
        insertar_final(lista, valor);
        return;
    }

    Nodo *nuevo = crear_nodo(valor);
    if (!nuevo) return;

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
}

// Busca un valor en la lista y devuelve el nodo (o NULL)
Nodo *buscar(Nodo *lista, int valor) {
    Nodo *actual = lista;
    while (actual != NULL) {
        if (actual->valor == valor) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

// Elimina el primer nodo que tenga el valor dado
void eliminar_valor(Nodo **lista, int valor) {
    if (lista == NULL || *lista == NULL) return;

    Nodo *actual = *lista;
    Nodo *anterior = NULL;

    // Caso: el primero es el que hay que eliminar
    if (actual->valor == valor) {
        *lista = actual->siguiente;
        free(actual);
        return;
    }

    // Recorro para encontrar el valor
    while (actual != NULL && actual->valor != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor %d no encontrado en la lista\n", valor);
        return;
    }

    anterior->siguiente = actual->siguiente;
    free(actual);
}

// Imprime los valores de la lista
void imprimir_lista(Nodo *lista) {
    Nodo *actual = lista;
    printf("[");
    while (actual != NULL) {
        printf("%d", actual->valor);
        if (actual->siguiente != NULL) printf(" -> ");
        actual = actual->siguiente;
    }
    printf("]\n");
}

// Libera toda la memoria de la lista
void liberar_lista(Nodo **lista) {
    if (lista == NULL) return;

    Nodo *actual = *lista;
    while (actual != NULL) {
        Nodo *tmp = actual;
        actual = actual->siguiente;
        free(tmp);
    }
    *lista = NULL;
}
