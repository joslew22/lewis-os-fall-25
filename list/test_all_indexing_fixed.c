#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    printf("=== TESTING ALL 1-BASED INDEXING FUNCTIONS ===\n");
    
    list_t *list = list_alloc();
    
    // Build the exact same test as your main.c
    list_add_to_front(list, 10);
    list_add_to_front(list, 20);
    list_add_to_front(list, 30);
    list_add_to_front(list, 40);
    list_add_to_front(list, 50);
    list_add_to_front(list, 60);
    list_add_to_front(list, 70);
    list_add_to_front(list, 80);
    list_add_to_front(list, 90);
    list_add_to_front(list, 100);
    
    printf("Initial list: ");
    list_print(list);
    
    printf("\n=== REMOVE SEQUENCE FROM MAIN.C ===\n");
    
    // Remove at index 3 (should remove 80)
    printf("Removing at index 3...\n");
    int r1 = list_remove_at_index(list, 3);
    printf("Removed: %d\n", r1);
    printf("List: ");
    list_print(list);
    
    // Remove at index 20 (should do nothing)
    printf("\nRemoving at index 20 (out of bounds)...\n");
    int r2 = list_remove_at_index(list, 20);
    printf("Removed: %d\n", r2);
    printf("List: ");
    list_print(list);
    
    // Remove at index 1 (should remove 100)
    printf("\nRemoving at index 1...\n");
    int r3 = list_remove_at_index(list, 1);
    printf("Removed: %d\n", r3);
    printf("List: ");
    list_print(list);
    
    // Remove at index 6 (should remove 30)
    printf("\nRemoving at index 6...\n");
    int r4 = list_remove_at_index(list, 6);
    printf("Removed: %d\n", r4);
    printf("List: ");
    list_print(list);
    
    char* final_str = listToString(list);
    printf("\nFinal result: %s\n", final_str);
    printf("Expected:     90->70->60->50->40->20->10->NULL\n");
    printf("Match: %s\n", (strcmp(final_str, "90->70->60->50->40->20->10->NULL") == 0) ? "YES!" : "NO");
    free(final_str);
    
    list_free(list);
    return 0;
}
