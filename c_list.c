#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_list.h"

#define INITIAL_CAPACITY 4

// Global array to track element types
list_data_type* data_types = NULL;
int data_capacity = 0;

void** create() {
    data_capacity = INITIAL_CAPACITY;
    data_types = (list_data_type*)malloc(data_capacity * sizeof(list_data_type));
    if (!data_types) {
        return NULL;
    }
    void** ptr = (void**)malloc(data_capacity * sizeof(void*));
    if (!ptr) {
        free(data_types);
        return NULL;
    }
    return ptr;
}

void** append(void** ptr, int* size, void* item, list_data_type type) {
    if (*size >= data_capacity) {
        data_capacity *= 2;
        data_types = (list_data_type*)realloc(data_types, data_capacity * sizeof(list_data_type));
        ptr = (void**)realloc(ptr, data_capacity * sizeof(void*));
        if (!data_types || !ptr) {
            return NULL;
        }
    }

    if (type == int_type) {
        int* new_item = (int*)malloc(sizeof(int));
        *new_item = *(int*)item;
        ptr[*size] = new_item;
    } else if (type == float_type) {
        float* new_item = (float*)malloc(sizeof(float));
        *new_item = *(float*)item;
        ptr[*size] = new_item;
    } else if (type == string_type) {
        char* new_item = strdup((char*)item);
        ptr[*size] = new_item;
    }

    data_types[*size] = type;
    (*size)++;
    return ptr;
}

void** pop(void** ptr, int* size) {
    if (*size <= 0) return ptr;

    (*size)--;
    if (data_types[*size] == int_type || data_types[*size] == float_type) {
        free(ptr[*size]);
    } else if (data_types[*size] == string_type) {
        free((char*)ptr[*size]);
    }
    return ptr;
}

void print(const void** ptr, int size) {
    for (int i = 0; i < size; i++) {
        if (data_types[i] == int_type) {
            printf("%d ", *(int*)ptr[i]);
        } else if (data_types[i] == float_type) {
            printf("%f ", *(float*)ptr[i]);
        } else if (data_types[i] == string_type) {
            printf("%s ", (char*)ptr[i]);
        }
    }
    printf("\n");
}

void destroy(void** ptr, int size) {
    for (int i = 0; i < size; i++) {
        if (data_types[i] == int_type || data_types[i] == float_type) {
            free(ptr[i]);
        } else if (data_types[i] == string_type) {
            free((char*)ptr[i]);
        }
    }
    free(data_types);
    free(ptr);
}
