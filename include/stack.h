#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    int data;   // Valor almacenado en este nodo             
    struct StackNode* next;  // Puntero al siguiente nodo 
} StackNode;

typedef struct {
    StackNode* top;    // Apunta al nodo en el tope de la pila
    int size;    // Cantidad de elementos en la pila   
} Stack;

// Funciones del stack
Stack* crearStack();   // Crea un nuevo stack en memoria dinámica y lo inicializa vacío
void push(Stack* stack, int data);   // Inserta un nuevo elemento en el tope del stack
int pop(Stack* stack);    // Elimina el elemento del tope y devuelve su valor
int peek(Stack* stack);   // Devuelve el valor del tope sin eliminarlo (stack no se modifica)
int isEmpty(Stack* stack);   // Retorna 1 si el stack está vacío, 0 si tiene elementos
void freeStack(Stack* stack);  // Libera todos los nodos y finalmente el stack completo
void printStack(Stack* stack);  // Imprime todos los elementos del stack sin modificarlo


#endif