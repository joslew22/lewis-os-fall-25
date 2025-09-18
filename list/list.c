// list.c
/*
// Implementation for linked list.
*/
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list_t *list_alloc() {
    list_t* mylist = (list_t *) malloc(sizeof(list_t));
    if (mylist == NULL) {
        return NULL; // Memory allocation failed
    }
    mylist->head = NULL;
    return mylist;
}

void list_free(list_t *l) {
    if (l == NULL) return;
    
    node_t *current = l->head;
    node_t *next;
    
    // Free all nodes
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    // Free the list structure itself
    free(l);
}

void list_print(list_t *l) {
    if (l == NULL || l->head == NULL) {
        printf("NULL\n");
        return;
    }
    
    node_t *current = l->head;
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("->NULL\n");
}

char * listToString(list_t *l) {
    char* buf = (char *) malloc(sizeof(char) * 10024);
    if (buf == NULL) return NULL;
    
    buf[0] = '\0'; // Initialize empty string
    char tbuf[20];
    
    if (l == NULL || l->head == NULL) {
        strcpy(buf, "NULL");
        return buf;
    }
    
    node_t* curr = l->head;
    while (curr != NULL) {
        sprintf(tbuf, "%d->", curr->value);
        strcat(buf, tbuf);
        curr = curr->next;
    }
    strcat(buf, "NULL");
    return buf;
}

int list_length(list_t *l) {
    if (l == NULL) return 0;
    
    int count = 0;
    node_t *current = l->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void list_add_to_back(list_t *l, elem value) {
    if (l == NULL) return;
    
    node_t *new_node = getNode(value);
    if (new_node == NULL) return; // Memory allocation failed
    
    // If list is empty, make new node the head
    if (l->head == NULL) {
        l->head = new_node;
        return;
    }
    
    // Traverse to the last node
    node_t *current = l->head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Add new node at the end
    current->next = new_node;
}

void list_add_to_front(list_t *l, elem value) {
    if (l == NULL) return;
    
    node_t *cur_node = (node_t *) getNode(value);
    if (cur_node == NULL) return; // Memory allocation failed
    
    /* Insert to front */
    node_t *head = l->head; // get head of list
    cur_node->next = head;
    l->head = cur_node;
}

node_t * getNode(elem value) {
    node_t *mynode = (node_t *) malloc(sizeof(node_t));
    if (mynode == NULL) return NULL; // Memory allocation failed
    
    mynode->value = value;
    mynode->next = NULL;
    return mynode;
}

void list_add_at_index(list_t *l, elem value, int index) {
    // Use 1-based indexing to match list_get_elem_at
    if (l == NULL || index < 1) return;
    
    // If index is 1, add to front
    if (index == 1) {
        list_add_to_front(l, value);
        return;
    }
    
    // If list is empty and index > 1, we can't insert
    if (l->head == NULL) return;
    
    node_t *current = l->head;
    int i;
    
    // Convert to 0-based for internal traversal (index-1)
    for (i = 0; i < index - 2 && current != NULL; i++) {
        current = current->next;
    }
    
    // If we couldn't reach the position, index is too large
    if (current == NULL) return;
    
    node_t *new_node = getNode(value);
    if (new_node == NULL) return; // Memory allocation failed
    
    // Insert the new node
    new_node->next = current->next;
    current->next = new_node;
}

elem list_remove_from_back(list_t *l) {
    if (l == NULL || l->head == NULL) return -1;
    
    // If there's only one element
    if (l->head->next == NULL) {
        elem value = l->head->value;
        free(l->head);
        l->head = NULL;
        return value;
    }
    
    // Find the second-to-last node
    node_t *current = l->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    // Remove the last node
    elem value = current->next->value;
    free(current->next);
    current->next = NULL;
    return value;
}

elem list_remove_from_front(list_t *l) {
    if (l == NULL || l->head == NULL) return -1;
    
    node_t *old_head = l->head;
    elem value = old_head->value;
    
    l->head = l->head->next;
    free(old_head);
    
    return value;
}

elem list_remove_at_index(list_t *l, int index) {
    // Use 1-based indexing to match list_get_elem_at
    if (l == NULL || l->head == NULL || index < 1) return -1;
    
    // If removing from front (index 1)
    if (index == 1) {
        return list_remove_from_front(l);
    }
    
    node_t *current = l->head;
    int i;
    
    // Convert to 0-based for internal traversal (index-2 to get to node before target)
    for (i = 0; i < index - 2; i++) {
        if (current == NULL || current->next == NULL) {
            return -1; // Index out of bounds
        }
        current = current->next;
    }
    
    // Check if the node to remove exists
    if (current == NULL || current->next == NULL) {
        return -1;
    }
    
    node_t *node_to_remove = current->next;
    elem value = node_to_remove->value;
    
    current->next = node_to_remove->next;
    free(node_to_remove);
    
    return value;
}

bool list_is_in(list_t *l, elem value) {
    if (l == NULL) return false;
    
    node_t *current = l->head;
    while (current != NULL) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

elem list_get_elem_at(list_t *l, int index) {
    // Header says "Starting index is 1" - so use 1-based indexing
    if (l == NULL || l->head == NULL || index < 1) return -1;
    
    node_t *current = l->head;
    int i;
    
    // Convert to 0-based for internal traversal
    for (i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) return -1;
    return current->value;
}

int list_get_index_of(list_t *l, elem value) {
    if (l == NULL) return -1;
    
    node_t *current = l->head;
    int index = 1;  // Start at 1 for 1-based indexing
    
    while (current != NULL) {
        if (current->value == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    
    return -1; // Element not found
}