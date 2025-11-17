#ifndef STACK_H
#define STACK_H

typedef struct Stacknode{    // Estructura para un nodo en el stack
    int data;         // Dato almacenado en el nodo
    struct Stacknode* next;   // Puntero al siguiente nodo 
} Stacknode;

typedef struct{    // Estructura de la pila
    Stacknode* top;    // Puntero que apunta a los mas alto de la pila
    int size;   // Dato almacenado
} Stack;

Stack* crearstack();   // Crea una nueva pila en memoria

void push(Stack* stack, int data);   // Agrega un elemento a al parte superior de la pila
int pop(Stack* stack);  // Elimina y devulve el elemento a la primera posisici´øn de la pila
int peek(Stack* stack);   // Devilve el elemento al inicio sin eliminarlo 
int isEmpty(Stack* stack);   // Verifica si la pila esta vacia 
void freeStack(Stack* stack);  //Libera el espacio de memoria de la pila
void printStack(Stack* stack);   // Hace print al contenido guardado en la pila 

#endif