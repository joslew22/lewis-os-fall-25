#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    printf("=== TESTING SCALING ===\n\n");
    
    // Test 1: Large number of additions
    printf("Test 1: Adding 1000 elements to front...\n");
    list_t *big_list = list_alloc();
    
    for (int i = 0; i < 1000; i++) {
        list_add_to_front(big_list, i);
        if (i % 200 == 0) {
            printf("  Added %d elements, length: %d\n", i+1, list_length(big_list));
        }
    }
    
    printf("Final length: %d\n", list_length(big_list));
    printf("First element: %d\n", list_get_elem_at(big_list, 0));
    printf("Last element: %d\n", list_get_elem_at(big_list, 999));
    
    // Test 2: Large number of removals
    printf("\nTest 2: Removing 500 elements from front...\n");
    int removed_count = 0;
    for (int i = 0; i < 500; i++) {
        int removed = list_remove_from_front(big_list);
        if (removed != -1) removed_count++;
        if (i % 100 == 0) {
            printf("  Removed %d elements, length: %d\n", removed_count, list_length(big_list));
        }
    }
    
    printf("After removals - length: %d\n", list_length(big_list));
    
    // Test 3: Mixed operations
    printf("\nTest 3: Mixed operations...\n");
    for (int i = 0; i < 100; i++) {
        list_add_at_index(big_list, 9999, i);
        if (i % 20 == 0) {
            printf("  Length after %d adds: %d\n", i+1, list_length(big_list));
        }
    }
    
    for (int i = 0; i < 100; i++) {
        list_remove_at_index(big_list, 0);
        if (i % 20 == 0) {
            printf("  Length after %d removes: %d\n", i+1, list_length(big_list));
        }
    }
    
    printf("Final length: %d\n", list_length(big_list));
    
    // Test 4: Stress test - rapid add/remove
    printf("\nTest 4: Stress test - rapid add/remove cycles...\n");
    for (int cycle = 0; cycle < 10; cycle++) {
        // Add 50 elements
        for (int i = 0; i < 50; i++) {
            list_add_to_back(big_list, i);
        }
        
        // Remove 30 elements
        for (int i = 0; i < 30; i++) {
            list_remove_from_front(big_list);
        }
        
        if (cycle % 2 == 0) {
            printf("  Cycle %d: length = %d\n", cycle, list_length(big_list));
        }
    }
    
    printf("After stress test: length = %d\n", list_length(big_list));
    
    // Cleanup
    printf("\nCleaning up...\n");
    list_free(big_list);
    printf("Cleanup complete!\n");
    
    return 0;
}
