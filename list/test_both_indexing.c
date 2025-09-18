#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    printf("=== TESTING BOTH INDEXING FUNCTIONS ===\n");
    
    list_t *list = list_alloc();
    
    // Create list: 10->20->30->40->NULL
    list_add_to_back(list, 10);
    list_add_to_back(list, 20);  
    list_add_to_back(list, 30);
    list_add_to_back(list, 40);
    
    printf("List: ");
    list_print(list);
    
    printf("\nTesting 1-based get_elem_at:\n");
    for (int i = 0; i <= 5; i++) {
        printf("Index %d: %d\n", i, list_get_elem_at(list, i));
    }
    
    printf("\nTesting 1-based get_index_of:\n");
    int values[] = {10, 20, 30, 40, 99};
    for (int i = 0; i < 5; i++) {
        int index = list_get_index_of(list, values[i]);
        printf("Value %d is at index: %d\n", values[i], index);
    }
    
    printf("\nConsistency check:\n");
    for (int i = 1; i <= 4; i++) {
        int value = list_get_elem_at(list, i);
        int found_index = list_get_index_of(list, value);
        printf("Index %d -> Value %d -> Found at index %d (%s)\n", 
               i, value, found_index, (i == found_index) ? "✓" : "✗");
    }
    
    list_free(list);
    return 0;
}
