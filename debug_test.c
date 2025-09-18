#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
    printf("=== DEBUGGING LINKED LIST ===\n\n");
    
    // Test 1: Add at index
    printf("TEST 1: Add at index\n");
    list_t *list1 = list_alloc();
    
    printf("Adding 10 at index 0 to empty list...\n");
    list_add_at_index(list1, 10, 0);
    list_print(list1);
    
    printf("Adding 20 at index 1...\n");
    list_add_at_index(list1, 20, 1);
    list_print(list1);
    
    printf("Adding 15 at index 1 (middle)...\n");
    list_add_at_index(list1, 15, 1);
    list_print(list1);
    
    list_free(list1);
    
    // Test 2: Remove functions
    printf("\nTEST 2: Remove functions\n");
    list_t *list2 = list_alloc();
    
    // Build list: 1->2->3
    list_add_to_back(list2, 1);
    list_add_to_back(list2, 2);
    list_add_to_back(list2, 3);
    printf("Initial list: ");
    list_print(list2);
    
    printf("Remove from front: %d\n", list_remove_from_front(list2));
    list_print(list2);
    
    printf("Remove from back: %d\n", list_remove_from_back(list2));
    list_print(list2);
    
    printf("Remove at index 0: %d\n", list_remove_at_index(list2, 0));
    list_print(list2);
    
    // Test empty list removes
    printf("Remove from empty front: %d\n", list_remove_from_front(list2));
    printf("Remove from empty back: %d\n", list_remove_from_back(list2));
    printf("Remove from empty at index 0: %d\n", list_remove_at_index(list2, 0));
    
    list_free(list2);
    
    // Test 3: Single element
    printf("\nTEST 3: Single element operations\n");
    list_t *list3 = list_alloc();
    list_add_to_front(list3, 42);
    printf("Single element list: ");
    list_print(list3);
    
    printf("Remove from back: %d\n", list_remove_from_back(list3));
    printf("After removal: ");
    list_print(list3);
    
    list_free(list3);
    
    printf("\n=== DEBUG COMPLETE ===\n");
    return 0;
}
