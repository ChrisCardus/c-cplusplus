#include <stdlib.h>
#include "freegraph.h"
#include <stdio.h>

// Define a linked list to store the nodes in.
typedef struct nodeList {
    struct N *node;
    struct nodeList *next;
} node_list;

// Define booleans for use in searching.
typedef int bool;
#define true 1
#define false 0

// Add a node to the end of the linked list.
void addNode(node_list *head, struct N *p) {
    // Create a variable so I can move through the list without changing the value of head.
    node_list *current = head;

    // Move to the end of the list.
    while(current->next) {
        current = current->next;
    }

    // Create a new node in the list
    node_list *new = malloc(sizeof(node_list));

    // Set the value on the list pointer to NULL as it's the end of the list.
    new->next = NULL;
    // Add the struct N to the list node.
    new->node = p;

    // Make the previous end of the list point to the new node.
    current->next = new;
}

// Search the list for a specific struct N. Return true if it's in the list, return false otherwise.
bool search(node_list *head, struct N *p) {
    // Create a variable so I can move through the list without changing the value of head.
    node_list *current = head;
    // Loop through the whole list.
    while(current) {
        // If the address of the given struct N matches that of the current list entry, return true.
        if(p == current->node) {
            return true;
        }
        // Iterate the list pointer.
        current = current->next;
    }
    return false;
}

// Add each node adjacent to the current one to the list. Deprecated.
/*
void mapGraph(node_list *head, struct N *p) {
    if(search(head, p->x) == false && p->x != NULL) {
        addNode(head, p->x);
    }
    if(search(head, p->y) == false && p->y != NULL) {
        addNode(head, p->y);
    }
    if(search(head, p->z) == false && p->z != NULL) {
        addNode(head, p->z);
    }
}*/

// Search the whole list of struct N for an entry where at least one of the edges is not in the list.
// Return either a struct N that matches this description or return false.
struct N* searchList(node_list *head) {
    // Create a variable so I can move through the list without changing the value of head.
    node_list *current = head->next;

    // Loop through the whole list.
    while(current) {
        // If the struct N via edge x isn't in the list, return it.
        if(search(head, current->node->x) == false && current->node->x != NULL) {
            return current->node->x;

        // If the struct N via edge y isn't in the list, return it.
        } else if (search(head, current->node->y) == false && current->node->y != NULL) {
            return current->node->y;

        // If the struct N via edge z isn't in the list, return it.
        } else if (search(head, current->node->z) == false && current->node->z != NULL) {
            return current->node->z;
        }

        // Iterate through the list.
        current = current->next;

    }
    return false;
}

// Count up the size of a list.
int listSize(node_list *head) {
    int size = 0;
    node_list *current = head;
    while(current) {
        size++;
        current = current->next;
    }
    return size;
}

// Move through the list and deallocate all the stuct Ns in the list, as well as the list itself.
void deallocateList(node_list *head) {
    int s = listSize(head);
    node_list *current = head;
    node_list *next = current->next;
    for(int i = 0; i < s; i++) {
        if(current->node != NULL) {
            free(current->node);
        }
        next = current->next;
        free(current);
        current = next;
    }
}

void deallocate(struct N *p) {

    // Create a pointer to the head of the list.
    node_list *head;
    // Allocate memory to the head of the list.
    head = malloc(sizeof(node_list));
    // Mark the next node as NULL.
    head->next = NULL;
    // The head of the list does not point to a struct N. 
    head->node = NULL;

    // Add the starting struct N to the list.
    addNode(head, p);

    // Create a pointer to p so that we can change the value without losing the value of p.
    struct N *cursor = p;

    // Loop while one of the edges attached to a struct N in the list is not contained in the list.
    while(searchList(head) != false) {
        // If the struct N along the edge x, y or z isn't in the list, add it to the list and move along that edge.
        if(search(head, cursor->x) == false && cursor->x != NULL) {
            addNode(head, cursor->x);
            cursor = cursor->x;
        } else if(search(head, cursor->y) == false && cursor->y != NULL) {
            addNode(head, cursor->y);
            cursor = cursor->y;
        } else if(search(head, cursor->z) == false && cursor->z != NULL) {
            addNode(head, cursor->z);
            cursor = cursor->z;

        // If all the edges currently visible have been explored and
        // there still exists an edge in the list that hasn't been explored, point the cursor at that new edge.
        } else if(searchList(head) != false) {
            cursor = searchList(head);
            addNode(head, cursor);
        }

    }

    deallocateList(head);
}