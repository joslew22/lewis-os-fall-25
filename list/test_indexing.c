#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    printf("=== TESTING INDEXING SYSTEM ===\n");
    
    list_t *list = list_alloc();
    
    // Create list: A->B->C->NULL
    list_add_to_back(list, 10);  // First element
    list_add_to_back(list, 20);  // Second element  
    list_add_to_back(list, 30);  // Third element
    
    printf("List: ");
    list_print(list);
    
    printf("\nTesting current 0-based indexing:\n");
    printf("Index 0: %d\n", list_get_elem_at(list, 0));
    printf("Index 1: %d\n", list_get_elem_at(list, 1)); 
    printf("Index 2: %d\n", list_get_elem_at(list, 2));
    printf("Index 3: %d\n", list_get_elem_at(list, 3));
    
    printf("\nIf it should be 1-based, then:\n");
    printf("Index 1 should return: 10 (first element)\n");
    printf("Index 2 should return: 20 (second element)\n");
    printf("Index 3 should return: 30 (third element)\n");
    printf("Index 0 should return: -1 (error)\n");
    
    list_free(list);
    return 0;
}
