#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void print_test_header(const char* test_name) {
    printf("\n=== %s ===\n", test_name);
}

void print_list_state(list_t *list, const char* description) {
    printf("%s: ", description);
    if (list == NULL) {
        printf("NULL list\n");
        return;
    }
    list_print(list);
    printf("Length: %d\n", list_length(list));
}

void test_add_at_index_systematically() {
    print_test_header("ADD_AT_INDEX SYSTEMATIC TEST");
    
    list_t *list = list_alloc();
    print_list_state(list, "Empty list");
    
    // Test 1: Add to empty list at index 0
    printf("\nTest 1: Add 10 at index 0 to empty list\n");
    list_add_at_index(list, 10, 0);
    print_list_state(list, "After add_at_index(10, 0)");
    
    // Test 2: Add to empty list at index > 0 (should fail gracefully)
    list_t *list2 = list_alloc();
    printf("\nTest 2: Add 20 at index 5 to empty list (should do nothing)\n");
    list_add_at_index(list2, 20, 5);
    print_list_state(list2, "After add_at_index(20, 5) on empty");
    list_free(list2);
    
    // Test 3: Add at end (should work like add_to_back)
    printf("\nTest 3: Add 20 at index 1 (end of list)\n");
    list_add_at_index(list, 20, 1);
    print_list_state(list, "After add_at_index(20, 1)");
    
    // Test 4: Add in middle
    printf("\nTest 4: Add 15 at index 1 (middle)\n");
    list_add_at_index(list, 15, 1);
    print_list_state(list, "After add_at_index(15, 1)");
    
    // Test 5: Add at front (index 0)
    printf("\nTest 5: Add 5 at index 0 (front)\n");
    list_add_at_index(list, 5, 0);
    print_list_state(list, "After add_at_index(5, 0)");
    
    // Test 6: Add beyond end
    printf("\nTest 6: Add 99 at index 10 (beyond end, should do nothing)\n");
    list_add_at_index(list, 99, 10);
    print_list_state(list, "After add_at_index(99, 10)");
    
    list_free(list);
}

void test_remove_functions_systematically() {
    print_test_header("REMOVE FUNCTIONS SYSTEMATIC TEST");
    
    // Test remove from empty list
    printf("\nTest 1: Remove from empty list\n");
    list_t *empty = list_alloc();
    printf("Remove from front of empty: %d\n", list_remove_from_front(empty));
    printf("Remove from back of empty: %d\n", list_remove_from_back(empty));
    printf("Remove at index 0 of empty: %d\n", list_remove_at_index(empty, 0));
    list_free(empty);
    
    // Test remove from single element list
    printf("\nTest 2: Remove from single element list\n");
    list_t *single = list_alloc();
    list_add_to_front(single, 42);
    print_list_state(single, "Single element list");
    
    printf("Remove from front: %d\n", list_remove_from_front(single));
    print_list_state(single, "After remove from front");
    
    // Reset single element list
    list_add_to_front(single, 42);
    printf("Remove from back: %d\n", list_remove_from_back(single));
    print_list_state(single, "After remove from back");
    
    // Reset single element list
    list_add_to_front(single, 42);
    printf("Remove at index 0: %d\n", list_remove_at_index(single, 0));
    print_list_state(single, "After remove at index 0");
    list_free(single);
    
    // Test remove from multi-element list
    printf("\nTest 3: Remove from multi-element list\n");
    list_t *multi = list_alloc();
    // Create list: 1->2->3->4->5
    for (int i = 1; i <= 5; i++) {
        list_add_to_back(multi, i);
    }
    print_list_state(multi, "Initial multi-element list");
    
    printf("Remove from front: %d\n", list_remove_from_front(multi));
    print_list_state(multi, "After remove from front");
    
    printf("Remove from back: %d\n", list_remove_from_back(multi));
    print_list_state(multi, "After remove from back");
    
    printf("Remove at index 1: %d\n", list_remove_at_index(multi, 1));
    print_list_state(multi, "After remove at index 1");
    
    printf("Remove at index 0: %d\n", list_remove_at_index(multi, 0));
    print_list_state(multi, "After remove at index 0");
    
    printf("Remove at index 0: %d\n", list_remove_at_index(multi, 0));
    print_list_state(multi, "After final remove at index 0");
    
    list_free(multi);
}

void test_edge_cases() {
    print_test_header("EDGE CASES TEST");
    
    printf("\nTest 1: NULL list operations\n");
    printf("Add to front of NULL: ");
    list_add_to_front(NULL, 10);
    printf("OK\n");
    
    printf("Remove from front of NULL: %d\n", list_remove_from_front(NULL));
    printf("Length of NULL: %d\n", list_length(NULL));
    
    printf("\nTest 2: Negative indices\n");
    list_t *list = list_alloc();
    list_add_to_front(list, 10);
    list_add_to_front(list, 20);
    print_list_state(list, "Test list");
    
    printf("Get element at index -1: %d\n", list_get_elem_at(list, -1));
    printf("Remove at index -1: %d\n", list_remove_at_index(list, -1));
    list_add_at_index(list, 99, -1);
    print_list_state(list, "After add at index -1");
    
    list_free(list);
}

void test_scaling() {
    print_test_header("SCALING TEST");
    
    list_t *list = list_alloc();
    
    printf("Adding 1000 elements to front...\n");
    for (int i = 0; i < 1000; i++) {
        list_add_to_front(list, i);
    }
    printf("List length: %d\n", list_length(list));
    printf("First element: %d\n", list_get_elem_at(list, 0));
    printf("Last element: %d\n", list_get_elem_at(list, 999));
    
    printf("Removing 500 elements from front...\n");
    for (int i = 0; i < 500; i++) {
        list_remove_from_front(list);
    }
    printf("List length after removals: %d\n", list_length(list));
    
    printf("Adding 100 elements at index 250...\n");
    for (int i = 0; i < 100; i++) {
        list_add_at_index(list, 9999 + i, 250);
    }
    printf("Final list length: %d\n", list_length(list));
    
    list_free(list);
}

int main() {
    printf("COMPREHENSIVE LINKED LIST DEBUG\n");
    printf("===============================\n");
    
    test_add_at_index_systematically();
    test_remove_functions_systematically();
    test_edge_cases();
    test_scaling();
    
    printf("\n=== DEBUG COMPLETE ===\n");
    return 0;
}
gcc -Wall -Wextra -std=c99 -g list.c systematic_debug.c -o debug_test
   ./debug_test
