void** list = create();
if (!list) {
printf("Failed to create list.\n");
return 1;
}
// Append elements to the list
int int_value = -6;
list = append(list, &size, &int_value, int_type); // Update pointer from append
float float_value = 0.1;
list = append(list, &size, &float_value, float_type); // Update pointer from append
char* string_value = "string_type";
list = append(list, &size, string_value, string_type); // Update pointer from append
// Print the list
printf("Original list:\n");
print((const void**)list, size);
// Remove last element
list = pop(list, &size); // Update pointer from pop
printf("List after pop:\n");
// Print after pop
print((const void**)list, size);
// Free memory
destroy(list, size);