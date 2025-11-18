#include <stdio.h>
#include <stdlib.h>
#include "lista.h"   // Solo listas, nada más

int main(void) {

<<<<<<< HEAD
    printf("\nDemostración de la Lista Enlazada\n");

    Nodo *lista = NULL;      // Empiezo con la lista vacía (NULL)

    // Inserto algunos valores para probar las funciones básicas de la lista
=======
    printf("\nDemostración del Stack\n");

    // Crea la pila vacía
    Stack* stack = crearStack();

    printf("Push 10\n");
    push(stack, 10);      // Agrega 10 al top
    printStack(stack);    // Imprime la pila

    printf("Push 13\n");
    push(stack, 13);     // Agrega 13 al top (LIFO)
    printStack(stack);   // Imprime la pila actualizada

    printf("Peek: %d\n", peek(stack));   // Muestra el elemento en el top sin sacarlo

    printf("Pop: %d\n", pop(stack));     // Saca el elemento del top
    printStack(stack);     // Imprime cómo queda la pila

    printf("Pop: %d\n", pop(stack));     // Saca el último elemento
    printStack(stack);    // No imprime nada ya que la pila queda vacía

    printf("isEmpty: %s\n", isEmpty(stack) ? "Sí" : "No");  // Verifica si está vacía

    freeStack(stack);    // Devuelve la memoria de la pila



    printf("\nDemostración de la Lista Enlazada\n");

    Nodo *lista = NULL;    // Empiezo con la lista vacía 

    // Inserta algunos valores para probar las funciones básicas de la lista
>>>>>>> feature/estructuras
    insertar_inicio(&lista, 5);        // Inserta 5 al inicio
    insertar_inicio(&lista, 10);       // Inserta 10 al inicio (queda antes del 5)
    insertar_final(&lista, 20);        // Inserta 20 al final
    insertar_posicion(&lista, 15, 2);  // Inserta 15 en la posición 2 (entre 10 y 5)

    printf("Lista actual: ");
<<<<<<< HEAD
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
=======
    imprimir_lista(lista);    // Imprime la lista

    // Prueba la función de búsqueda
    Nodo* buscado = buscar(lista, 15); // Busca el valor 15 en la lista
    printf("Buscar 15: %s\n", buscado ? "Encontrado" : "No encontrado");

    // Prueba de eliminar por valor
    eliminar_valor(&lista, 10);   // Elimina el nodo con valor 10
    printf("Lista después de eliminar 10: ");
    imprimir_lista(lista);

    liberar_lista(&lista);   // Libera la memoria


    printf("\nDemostración Arreglo Dinámico\n");

    DynamicArray* arr = createArray(2);   // Arreglo dinámico con capacidad inicial 2

    insertElement(arr, 10);   // Inserta 10
    insertElement(arr, 20);   // Inserta 20
    insertElement(arr, 30);   // Inserta 30 (debería aumentar la capacidad)

    printArray(arr);  // Imprime el arreglo

    printf("Elemento en índice 1: %d\n", getElement(arr, 1));  // Muestra el elemento en la posición 1

    printf("Eliminar elemento en índice 1\n");
    removeAt(arr, 1);    // Elimina el elemento en la posición 1

    printArray(arr);   // Vuelve a imprimir el arreglo

    freeArray(arr);   // Libera la memoria del arreglo

    printf("\nDemostración Finalizada :)\n");

    return 0;

} 
>>>>>>> feature/estructuras
