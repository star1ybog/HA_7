#ifndef C_LIST_H
#define C_LIST_H

// Enum to identify the data type (int, float, or string)
typedef enum {
    int_type,   // For integer values
    float_type, // For float values
    string_type // For string (char*) values
} list_data_type;

// Creates a dynamic array and returns a pointer to it
// Returns NULL if memory allocation fails
void** create();

// Appends a new element (int, float, or string) to the array
// Automatically resizes the array (realloc) and updates size correspondingly
// Returns pointer to the reallocated memory
void** append(void** ptr, int* size, void* item, list_data_type type);

// Removes the last element from the array and frees its memory
// Updates the size of the array accordingly
// Returns pointer to the reallocated memory
void** pop(void** ptr, int* size);

// Prints all elements in the array based on their types (int, float, or string)
void print(const void** ptr, int size);

// Frees all allocated memory for the array and its elements
void destroy(void** ptr, int size);

#endif // C_LIST_H
