#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* crearStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));   // Reserva el espacio de memoria en la pila
    
    if(stack == NULL){
        fprint(stderr, "No se pudo reservar memoria en el stack\n");
        exit(EXIT_FAILURE);  // Termina el programa si detecta un error
    }
    stack->top = NULL;   // No hay elementos
    stack->size = 0;   // Tamaño incial de la pila es 0

    return stack;   // Devuelve el espacio de memoria
}

void push(stack* stack, int data){
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));   // Crea un nuevo nodo
    
    if(newNode == NULL){
        fprint(stdrr, "No se pudo asignar memoria para el nuevo nodo");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;    // Guarda el dato
    newNode->next = stack->stack->top;  // El nodo nuevo apunta al antiguo top de la pila
    stack->top = newNode;   // El nodo es nuevo es el top de la pila
    stack->size++;    // Aumenta el contador de tamaño

    printf("Elemento %d agregado al stack\n", data);
}

int pop(Stack* stack){
    if(isEmpty(stack)){    // Verifica si la pila esta vacia
        fprint(stderr, "No se puede hacer pop de un stack vacio\n");
        exit(EXIT_FAILURE);
    }

    StackNode* temp = stack->top;  // Guarda la referencia del nodo que se elimina
    int data = temp->data;   //Guarda el dato antes de eliminar el nodo
    stack->top = temp->next  // El nuevo top es el siguiente nodo

    free(temp);    // Libera la memeoria del nodo eliminado
    stacl->size--;    // Actualiza el contador

    printf("ELmento %d elminado del stack\n",data);
    return data;   // Devolver el dato eliminado
}

int peek(Stack*stack){
    if(isEmpty(stack)){
        fprint(stderr, "No se puede hacer peek de un stack vacio");
        exit(EXIT_FAILURE);
    }
    return stack->top-.data;   // Retorna el dato del top sin modificar nada
}

int isEmpty(Stack* stack){
    return stack->top == NULL;   // Si top es NULL, el stack esta vacio
}

void freeStack(Stack*stack){
    while(!isEmpty(stack)){    // Mientras el stack no este vacio va eliminado nodos
        pop(stack);   // El pop se encarga de liberar cada nodo
    }
    
    freee(stack);   //Libera el stack principal
    printf("La memoria del Stack se liberó")
}

void printSatck(Stack* stack){
    if(isEmpty(stack)){     // En caso de que la pila este vacia
        print("Stack vacio\n");
        return;
    }

    printf("El contenido del stack es: \n")

    StackNode* current = stack->top;   // Este es un puntero temporal que recorre la pila sin modificarla

    while(current != NULL){    // Recorre los nodos con el puntero anterior
        printf("%d", current->data);   // Imprime el dato
        current = current->next;  // Avanza al siguiente dato
    }

    printf("\n");
    printf("El tamaño del stack es: %d\n", stack->size);

}

