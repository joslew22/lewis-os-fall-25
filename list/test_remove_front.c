#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_remove_test(const char* test, int expected_return, int actual_return, int expected_len, int actual_len, const char* expected_list, const char* actual_list) {
    printf("%s:\n", test);
    printf("  Expected return: %d, got: %d - %s\n", expected_return, actual_return, (expected_return == actual_return) ? "✓" : "✗");
    printf("  Expected length: %d, got: %d - %s\n", expected_len, actual_len, (expected_len == actual_len) ? "✓" : "✗");
    printf("  Expected list: %s\n", expected_list);
    printf("  Actual list:   %s\n", actual_list);
    printf("\n");
}

int main() {
    printf("=== TESTING REMOVE_FROM_FRONT ONLY ===\n\n");
    
    // Test 1: Remove from empty list
    printf("Test 1: Remove from empty list\n");
    list_t *test1 = list_alloc();
    int result1 = list_remove_from_front(test1);
    char* list1_str = listToString(test1);
    print_remove_test("Remove from empty", -1, result1, 0, list_length(test1), "NULL", list1_str);
    free(list1_str);
    list_free(test1);
    
    // Test 2: Remove from single element list
    printf("Test 2: Remove from single element list\n");
    list_t *test2 = list_alloc();
    list_add_to_front(test2, 42);
    int result2 = list_remove_from_front(test2);
    char* list2_str = listToString(test2);
    print_remove_test("Remove from single element", 42, result2, 0, list_length(test2), "NULL", list2_str);
    free(list2_str);
    list_free(test2);
    
    // Test 3: Remove from two element list
    printf("Test 3: Remove from two element list\n");
    list_t *test3 = list_alloc();
    list_add_to_back(test3, 10);
    list_add_to_back(test3, 20);  // Now: 10->20->NULL
    int result3 = list_remove_from_front(test3);
    char* list3_str = listToString(test3);
    print_remove_test("Remove front from 10->20", 10, result3, 1, list_length(test3), "20->NULL", list3_str);
    free(list3_str);
    list_free(test3);
    
    // Test 4: Remove multiple times
    printf("Test 4: Remove multiple from front\n");
    list_t *test4 = list_alloc();
    list_add_to_back(test4, 1);
    list_add_to_back(test4, 2);
    list_add_to_back(test4, 3);  // Now: 1->2->3->NULL
    
    int r1 = list_remove_from_front(test4);
    printf("  First remove: expected 1, got %d - %s\n", r1, (r1 == 1) ? "✓" : "✗");
    
    int r2 = list_remove_from_front(test4);
    printf("  Second remove: expected 2, got %d - %s\n", r2, (r2 == 2) ? "✓" : "✗");
    
    int r3 = list_remove_from_front(test4);
    printf("  Third remove: expected 3, got %d - %s\n", r3, (r3 == 3) ? "✓" : "✗");
    
    char* list4_str = listToString(test4);
    printf("  Final list: expected NULL, got %s - %s\n", list4_str, (strcmp(list4_str, "NULL") == 0) ? "✓" : "✗");
    free(list4_str);
    
    // Test removing from now-empty list
    int r4 = list_remove_from_front(test4);
    printf("  Remove from empty: expected -1, got %d - %s\n", r4, (r4 == -1) ? "✓" : "✗");
    
    list_free(test4);
    
    return 0;
}
