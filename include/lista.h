#ifndef LISTA_H
#define LISTA_H

// Estructura del nodo
typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Funciones de la lista
void insertar_inicio(Nodo **lista, int valor);
void imprimir_lista(Nodo *lista);
void liberar_lista(Nodo **lista);

#endif
