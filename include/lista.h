#ifndef LISTA_H
#define LISTA_H

// Nodo de la lista enlazada simple
typedef struct Nodo {
    int valor;
    struct Nodo *siguiente;
} Nodo;

// Crea un nodo nuevo
Nodo *crear_nodo(int valor);

// Inserciones
void insertar_inicio(Nodo **lista, int valor);
void insertar_final(Nodo **lista, int valor);
void insertar_posicion(Nodo **lista, int valor, int posicion);

// Búsqueda
Nodo *buscar(Nodo *lista, int valor);

// Eliminación
void eliminar_valor(Nodo **lista, int valor);

// Utilidades
void imprimir_lista(Nodo *lista);
void liberar_lista(Nodo **lista);

#endif
