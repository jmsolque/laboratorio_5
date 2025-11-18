#include <stdio.h>      
#include <stdlib.h>     
#include "stack.h" 

// Función para crear un nuevo stack vacío
Stack* crearStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));   // Reserva memoria para la estructura Stack
    if (!stack) {        // Verifica si malloc falló
        fprintf(stderr, "No se pudo reservar memoria para el stack\n");
        exit(EXIT_FAILURE);    // Termina la ejecución del programa en caso de error
    }
    stack->top = NULL;   // Inicializa el puntero top como NULL (stack vacío)
    stack->size = 0;     // Inicializa el tamaño en 0
    return stack;        // Devuelve el stack creado
}

// Inserta un elemento en el tope del stack
void push(Stack* stack, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));  // Reserva memoria para nuevo nodo
    if (!newNode) {       // Verifica error de memoria
        fprintf(stderr, "No se pudo reservar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;     // Guarda el dato en el nuevo nodo
    newNode->next = stack->top;  // Apunta el nuevo nodo al nodo actual del tope
    stack->top = newNode;     // Actualiza el tope al nuevo nodo
    stack->size++;     // Incrementa el tamaño del stack
}

// Elimina y retorna el elemento del tope
int pop(Stack* stack) {
    if (isEmpty(stack)) {     // Verifica si el stack está vacío
        fprintf(stderr, "No se puede hacer pop de un stack vacío\n");
        exit(EXIT_FAILURE);
    }

    StackNode* temp = stack->top;   // Guarda el nodo del tope
    int data = temp->data;    // Guarda el dato del nodo para retornarlo

    stack->top = temp->next; // Mueve el tope al siguiente nodo
    free(temp);      // Libera la memoria del nodo eliminado
    stack->size--;  // Reduce el tamaño del stack

    return data;    // Devuelve el valor eliminado
}

// Devuelve el elemento del tope sin eliminarlo
int peek(Stack* stack) {
    if (isEmpty(stack)) {     // Verifica si está vacío
        fprintf(stderr, "No se puede hacer peek de un stack vacío\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;     // Retorna el dato del tope
}


int isEmpty(Stack* stack) {
    return stack->top == NULL;    // El stack está vacío si top es NULL
}

// Libera toda la memoria del stack
void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {  // Mientras haya elementos enel stack los elimina uno por uno
        pop(stack);           
    }
    free(stack);    // Libera la estructura principal
}

void printStack(Stack* stack) {
    if (isEmpty(stack)) {     // Si no hay elementos
        printf("Stack vacío\n");
        return;
    }

    printf("Contenido del stack:\n");
    StackNode* current = stack->top;   // Empieza desde el tope
    while (current) {    // Recorre todos los nodos
        printf("%d ", current->data);  // Imprime el valor del nodo actual
        current = current->next;    // Avanza al siguiente nodo
    }
    printf("\nTamaño actual: %d\n", stack->size);  // Imprime el tamaño del stack
}