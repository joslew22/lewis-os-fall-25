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
    printf("=== TESTING REMOVE_AT_INDEX ONLY ===\n\n");
    
    // Test 1: Remove from empty list
    printf("Test 1: Remove from empty list\n");
    list_t *test1 = list_alloc();
    int result1 = list_remove_at_index(test1, 0);
    char* list1_str = listToString(test1);
    print_remove_test("Remove at index 0 from empty", -1, result1, 0, list_length(test1), "NULL", list1_str);
    free(list1_str);
    list_free(test1);
    
    // Test 2: Remove from single element list at index 0
    printf("Test 2: Remove from single element at index 0\n");
    list_t *test2 = list_alloc();
    list_add_to_front(test2, 42);
    int result2 = list_remove_at_index(test2, 0);
    char* list2_str = listToString(test2);
    print_remove_test("Remove at index 0 from single", 42, result2, 0, list_length(test2), "NULL", list2_str);
    free(list2_str);
    list_free(test2);
    
    // Test 3: Remove at invalid index from single element
    printf("Test 3: Remove at invalid index from single element\n");
    list_t *test3 = list_alloc();
    list_add_to_front(test3, 42);
    int result3 = list_remove_at_index(test3, 5);
    char* list3_str = listToString(test3);
    print_remove_test("Remove at index 5 from single", -1, result3, 1, list_length(test3), "42->NULL", list3_str);
    free(list3_str);
    list_free(test3);
    
    // Test 4: Remove from middle of list
    printf("Test 4: Remove from middle of list\n");
    list_t *test4 = list_alloc();
    list_add_to_back(test4, 1);
    list_add_to_back(test4, 2);
    list_add_to_back(test4, 3);  // Now: 1->2->3->NULL
    
    char* before_str = listToString(test4);
    printf("  Before: %s\n", before_str);
    free(before_str);
    
    int result4 = list_remove_at_index(test4, 1);  // Remove middle element (2)
    char* list4_str = listToString(test4);
    print_remove_test("Remove at index 1 from 1->2->3", 2, result4, 2, list_length(test4), "1->3->NULL", list4_str);
    free(list4_str);
    list_free(test4);
    
    // Test 5: Remove last element by index
    printf("Test 5: Remove last element by index\n");
    list_t *test5 = list_alloc();
    list_add_to_back(test5, 10);
    list_add_to_back(test5, 20);
    list_add_to_back(test5, 30);  // Now: 10->20->30->NULL
    
    int result5 = list_remove_at_index(test5, 2);  // Remove last element (30)
    char* list5_str = listToString(test5);
    print_remove_test("Remove at index 2 from 10->20->30", 30, result5, 2, list_length(test5), "10->20->NULL", list5_str);
    free(list5_str);
    list_free(test5);
    
    // Test 6: Remove with negative index
    printf("Test 6: Remove with negative index\n");
    list_t *test6 = list_alloc();
    list_add_to_back(test6, 100);
    int result6 = list_remove_at_index(test6, -1);
    char* list6_str = listToString(test6);
    print_remove_test("Remove at index -1", -1, result6, 1, list_length(test6), "100->NULL", list6_str);
    free(list6_str);
    list_free(test6);
    
    // Test 7: Multiple removes by index
    printf("Test 7: Multiple removes by index\n");
    list_t *test7 = list_alloc();
    for (int i = 1; i <= 5; i++) {
        list_add_to_back(test7, i);  // 1->2->3->4->5->NULL
    }
    
    char* start_str = listToString(test7);
    printf("  Start: %s\n", start_str);
    free(start_str);
    
    int r1 = list_remove_at_index(test7, 2);  // Remove 3
    printf("  Remove index 2: expected 3, got %d - %s\n", r1, (r1 == 3) ? "✓" : "✗");
    
    char* after1_str = listToString(test7);
    printf("  After: %s\n", after1_str);
    free(after1_str);
    
    int r2 = list_remove_at_index(test7, 0);  // Remove 1 
    printf("  Remove index 0: expected 1, got %d - %s\n", r2, (r2 == 1) ? "✓" : "✗");
    
    char* final_str = listToString(test7);
    printf("  Final: %s\n", final_str);
    free(final_str);
    
    list_free(test7);
    
    return 0;
}
