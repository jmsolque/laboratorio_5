#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "lista.h"
#include "array.h"

int main(void) {

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
    
    
    printf("\nDemostración de la Lista Enlazada\n");

    Nodo *lista = NULL;  // Inicia la lista con NULL

    insertar_inicio(&lista, 5);       // Incerta un 5
    insertar_inicio(&lista, 10);      // Incerta un 10
    insertar_final(&lista, 20);       // Incerta un 20
    insertar_posicion(&lista, 15, 2);    // Incerta un 15 en la posición 2

    printf("Lista actual: ");   
    imprimir_lista(lista);    // Imprime la lista 

    Nodo* buscado = buscar(lista, 15);     // Busca el valor con un puntero 
    printf("Buscar 15: %s\n", buscado ? "Encontrado" : "No encontrado");   // Indica si encontro el valor buscado

    eliminar_valor(&lista, 10);     // Elimina el nodo con valor 10
    printf("Lista después de eliminar 10: "); 
    imprimir_lista(lista);  

    liberar_lista(&lista);   // Libera nodo por nodo hasta que la lista queda NULL

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