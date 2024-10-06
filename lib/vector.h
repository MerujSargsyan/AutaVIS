#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define len(A) (int)(sizeof((A)) / sizeof((A)[0]))

typedef struct vector {
    void** arr;
    int size;
    int capacity;
} vector;

// USER RESPONSIBLE FOR FREEING using free_vector
vector init_vector(int capacity);
void free_vector(vector* vect); 
void vector_add(vector* vect, void *element);
void* vector_pop(vector* vect);
void vector_swap(vector* vect, int i1, int i2);
