/// array.h
#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray* createArray(size_t initialCapacity);
void insertElement(DynamicArray* arr, int element);
void removeAt(DynamicArray* arr, size_t index);
int getElement(const DynamicArray* arr, size_t index);
void printArray(const DynamicArray* arr);
void freeArray(DynamicArray* arr);

#endif

