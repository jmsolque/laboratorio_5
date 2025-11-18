#include <stdio.h>
#include <stdlib.h>
#include "lista.h"   // Solo listas, nada más

int main(void) {

    printf("\nDemostración de la Lista Enlazada\n");

    Nodo *lista = NULL;      // Empiezo con la lista vacía (NULL)

    // Inserto algunos valores para probar las funciones básicas de la lista
    insertar_inicio(&lista, 5);        // Inserta 5 al inicio
    insertar_inicio(&lista, 10);       // Inserta 10 al inicio (queda antes del 5)
    insertar_final(&lista, 20);        // Inserta 20 al final
    insertar_posicion(&lista, 15, 2);  // Inserta 15 en la posición 2 (entre 10 y 5)

    printf("Lista actual: ");
    imprimir_lista(lista);             // Muestra cómo quedó la lista

    // Pruebo la función de búsqueda
    Nodo* buscado = buscar(lista, 15); // Busco el valor 15 en la lista
    printf("Buscar 15: %s\n", buscado ? "Encontrado" : "No encontrado");

    // Pruebo eliminar por valor
    eliminar_valor(&lista, 10);        // Elimino el nodo con valor 10
    printf("Lista después de eliminar 10: ");
    imprimir_lista(lista);

    // Al final libero la memoria de toda la lista
    liberar_lista(&lista);

    return 0;
}
