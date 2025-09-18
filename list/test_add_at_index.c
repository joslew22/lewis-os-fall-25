#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_test_result(const char* test, int expected_len, int actual_len, const char* expected_list, const char* actual_list) {
    printf("%s:\n", test);
    printf("  Expected length: %d, got: %d - %s\n", expected_len, actual_len, (expected_len == actual_len) ? "✓" : "✗");
    printf("  Expected list: %s\n", expected_list);
    printf("  Actual list:   %s\n", actual_list);
    printf("\n");
}

int main() {
    printf("=== TESTING ADD_AT_INDEX ONLY ===\n\n");
    
    // Test 1: Add to empty list at index 0
    printf("Test 1: Add to empty list at index 0\n");
    list_t *test1 = list_alloc();
    list_add_at_index(test1, 10, 0);
    char* result1 = listToString(test1);
    print_test_result("Add 10 at index 0 to empty", 1, list_length(test1), "10->NULL", result1);
    free(result1);
    list_free(test1);
    
    // Test 2: Add to empty list at index > 0 (should do nothing)
    printf("Test 2: Add to empty list at index 1 (should fail)\n");
    list_t *test2 = list_alloc();
    list_add_at_index(test2, 10, 1);
    char* result2 = listToString(test2);
    print_test_result("Add 10 at index 1 to empty", 0, list_length(test2), "NULL", result2);
    free(result2);
    list_free(test2);
    
    // Test 3: Add at end of existing list
    printf("Test 3: Add at end of existing list\n");
    list_t *test3 = list_alloc();
    list_add_to_front(test3, 20);
    list_add_to_front(test3, 10);  // Now: 10->20->NULL
    list_add_at_index(test3, 30, 2);  // Add at end
    char* result3 = listToString(test3);
    print_test_result("Add 30 at index 2", 3, list_length(test3), "10->20->30->NULL", result3);
    free(result3);
    list_free(test3);
    
    // Test 4: Add in middle
    printf("Test 4: Add in middle of list\n");
    list_t *test4 = list_alloc();
    list_add_to_front(test4, 30);
    list_add_to_front(test4, 10);  // Now: 10->30->NULL
    list_add_at_index(test4, 20, 1);  // Insert 20 between 10 and 30
    char* result4 = listToString(test4);
    print_test_result("Add 20 at index 1", 3, list_length(test4), "10->20->30->NULL", result4);
    free(result4);
    list_free(test4);
    
    // Test 5: Add beyond end (should fail)
    printf("Test 5: Add beyond end of list (should fail)\n");
    list_t *test5 = list_alloc();
    list_add_to_front(test5, 20);
    list_add_to_front(test5, 10);  // Now: 10->20->NULL (length 2)
    list_add_at_index(test5, 99, 5);  // Try to add at index 5
    char* result5 = listToString(test5);
    print_test_result("Add 99 at index 5 to 2-element list", 2, list_length(test5), "10->20->NULL", result5);
    free(result5);
    list_free(test5);
    
    return 0;
}
