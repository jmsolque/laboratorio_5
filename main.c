#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "lista.h"
#include "array.h"

int main() {

    printf("\nDemostración del Stack\n");

    Stack* stack = crearstack();    // Llama la función crearstack que  reserva el espacio de memoria con top = NULL y size = 0

    printf("Push 10\n");
    push(stack, 10);       // Afrega el 10 al top de la pila
    printStack(stack);     // Imprime la actualización de la pila

    printf("Push 20\n");   
    push(stack, 13);      // Agrega el 13 a al top, respetando LIFO  que es la estructura de la pila
    printStack(stack);    // Imprime el nuevo top de la pila

    printf("Peek: %d\n", peek(stack));   // Muestra el elemento del top sin eliminarlo

    printf("Pop: %d\n", pop(stack));   // Elimina y devuelve el elemento que esta en el top
    printStack(stack);   // Imprime la pila luego de eliminar el elemento

    printf("Pop: %d\n", pop(stack));  // Saca el unico elemento que queda dejando la pila vacia
    printStack(stack);    // Imprime un espacio vacio demostrando que se elimino lo ultimo
 
    printf("isEmpty: %s\n", isEmpty(stack) ? "Sí" : "No");   // isEmpty retorna 1 y por lo tanto un "Sí", si la pila esta vacia

    freeStack(stack);  // Libera el espacio de memoria de la pila 
    
    
    /* ===================== PARTE LISTA ENLAZADA  ===================== */

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
    eliminar_valor(&lista, 10);        // Elimino el nodo que tiene el valor 10
    printf("Lista después de eliminar 10: ");
    imprimir_lista(lista);

    // Al final libero la memoria de toda la lista
    liberar_lista(&lista);

    /* ================== FIN PARTE LISTA ENLAZADA  ==================== */


    printf("\nDemostración Arreglo Dinamico\n");

    DynamicArray* arr = createArray(2);   // Reserva la memeoria para un array inicial de 2 elementos

    insertElement(arr, 10);  // Incerta 10
    insertElement(arr, 20);  // Incerta 20
    insertElement(arr, 30);  // Incerta 30, al ingresar otro valor que supera la capacidad de la memoria, este la aumenta

    printArray(arr);   // imprime el array nuevo

    printf("Elemento en índice 1: %d\n", getElement(arr, 1));   // Retorna el numero en la posición 1, esto inciando en 0,...,n

    printf("Eliminar elemento en índice 1\n");   // Elimina el numero en la posición 1
    removeAt(arr, 1);

    printArray(arr);   // Imprime de nuevo el array

    freeArray(arr);   // Libera el espacio de memoria

    printf("\n Demostración Finalizada :)\n");

    return 0;
}
