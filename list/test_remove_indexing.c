#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    printf("=== TESTING REMOVE_AT_INDEX INDEXING ===\n");
    
    list_t *list = list_alloc();
    
    // Build the exact same list as your main.c test
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
    printf("Length: %d\n", list_length(list));
    
    printf("\nTesting what each index contains:\n");
    for (int i = 1; i <= 10; i++) {
        printf("Index %d (1-based): %d\n", i, list_get_elem_at(list, i));
    }
    
    printf("\n=== REMOVE OPERATIONS ===\n");
    printf("Removing at index 3...\n");
    int removed = list_remove_at_index(list, 3);
    printf("Removed: %d\n", removed);
    printf("List after: ");
    list_print(list);
    
    printf("\nWhat your main.c expects after all removes: 90->70->60->50->40->20->10->NULL\n");
    printf("Let's see what sequence of removes would give that result...\n");
    
    list_free(list);
    return 0;
}
