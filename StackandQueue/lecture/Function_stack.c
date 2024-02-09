#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

void push(node** head_ref, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void pop(node ** head_ref){
    node * ptr;
    ptr = *head_ref;
    *head_ref = (*head_ref)->next;
    free(ptr);
}

void peek(node * head_ref){
    printf("%d\n", head_ref->data);
}

void traverse(node* start) {
    node* ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main ()
{
    node* head = NULL;
    for (int i = 0; i < 10; i++)
        push(&head, i);
    traverse(head);
}