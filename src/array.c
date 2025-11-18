//// array.c
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

DynamicArray* createArray(size_t initialCapacity) {
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (!arr) return NULL;
    arr->data = malloc(initialCapacity * sizeof(int));
    if (!arr->data) {
        free(arr);
        return NULL;
    }
    arr->size = 0;
    arr->capacity = initialCapacity;
    return arr;
}

void insertElement(DynamicArray* arr, int element) {
    if (!arr) return;
    if (arr->size == arr->capacity) {
        size_t newCapacity = (arr->capacity == 0) ? 1 : arr->capacity * 2;
        int *newData = realloc(arr->data, newCapacity * sizeof(int));
        if (!newData) {
            fprintf(stderr, "Error ampliando el array\n");
            return;
        }
        arr->data = newData;
        arr->capacity = newCapacity;
    }
    arr->data[arr->size++] = element;
}

void removeAt(DynamicArray* arr, size_t index) {
    if (!arr || index >= arr->size) return;
    for (size_t i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

int getElement(const DynamicArray* arr, size_t index) {
    if (!arr || index >= arr->size) {
        fprintf(stderr, "Índice fuera de rango\n");
        return 0;
    }
    return arr->data[index];
}

void printArray(const DynamicArray* arr) {
    if (!arr) return;
    printf("[");
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]\n");
}

void freeArray(DynamicArray* arr) {
    if (!arr) return;
    free(arr->data);
    free(arr);
}
