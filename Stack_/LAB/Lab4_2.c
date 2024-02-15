// Punnawat Mungakalarungsi 66070503436
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
    if (ptr == NULL) {
        printf("empty\n");
        return;
    }
    printf("%d\n", ptr->data);
    *head_ref = (*head_ref)->next;
    free(ptr);
}

void peek(node * head_ref){
    if (head_ref == NULL) {
        printf("empty\n");
        return;
    }
    printf("%d\n", head_ref->data);
}

void is_empty(node * head_ref){
    if (head_ref == NULL) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
}

int main ()
{
    node* head = NULL;
    char command;
    while (1)
    {
        scanf("%c", &command);
        if (command == 'p') {
            int data;
            scanf("%d", &data);
            push(&head, data);
        }
        else if (command == 'o') {
            pop(&head);
        }
        else if (command == 'e') {
            is_empty(head);
        }
        else if (command == 't') {
            peek(head);
        }
        else if (command == 'q') {
            break;
        }
    }
    return 0;
    
}