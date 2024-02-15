// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

void push(node** head_ref, int data, int n);
void pop(node ** head_ref);
void show(node* start);
int number_elements(node* start);
void exitProgram();

void push(node** head_ref, int data, int n) {
    if (number_elements(*head_ref) == n) {
        printf("Stack Overflow.\n");
        exit(0);
    }
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void pop(node ** head_ref){
    node * ptr;
    ptr = *head_ref;
    if (ptr == NULL) {
        printf("Stack Underflow.\n");
        exit(0);
    }
    *head_ref = (*head_ref)->next;
    free(ptr);
}

void show(node* start) {
    node* ptr = start;
    if (ptr == NULL) {
        printf("Stack is empty.\n");
        exit(0);
    }
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    exit(0);
}

int number_elements(node* start) {
    node* ptr = start;
    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void exitProgram() {
    printf("Exiting...\n");
    exit(0);
}

int main ()
{
    int n;
    scanf("%d", &n);
    if (n < 1) {
        printf("Please enter a positive number.\n");
        return 0;
    }
    node* head = NULL;
    while (true) {
        int choice, val;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &val);
                push(&head, val, n);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                show(head);
                break;
            case 4:
                exitProgram();
                break;
            default:
                printf("Invalid choice.");
                return 0;
        }
    }
    return 0;
}