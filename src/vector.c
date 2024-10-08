#include <vector.h>

// IMPORTANT!!!:
// Implementing a getter for this structure was pointless because
// of the type being so general. The user must do the following:
//
// T value = *(T *)(vector.arr[i]);
//
// The onlyt thing a getter would have is {return vector.arr[i];}

// USER RESPONSIBLE FOR FREEING using free_vector
vector init_vector(int capacity) {
    vector vect;
    vect.arr = malloc(capacity * sizeof(void *));
    vect.size = 0;
    vect.capacity = capacity;
    return vect;
}

void free_vector(vector* vect) {
    free(vect->arr);
}

void vector_add(vector* vect, void *element) {
    // test for resize
    if(vect->size > vect->capacity/2)  {
        vect->capacity *= 2;
        vect->arr = realloc(vect->arr, vect->capacity * sizeof(void *)); 
    }

    vect->arr[vect->size] = element;
    vect->size++;
}

void* vector_pop(vector* vect) {
    void* output = vect->arr[0];

    for(int i = 1; i < vect->size; i++) {
        vect->arr[i-1] = vect->arr[i];
    }

    vect->size--;
    return output;
}

void vector_swap(vector* vect, int i1, int i2) {
    void* entry1 = vect->arr[i1];
    void* entry2 = vect->arr[i2];
    void* temp = malloc(sizeof(void *));
    memcpy(temp, entry1, sizeof(entry1));
    vect->arr[i1] = entry2; 
    vect->arr[i2] = temp;
    free(entry1);
}
