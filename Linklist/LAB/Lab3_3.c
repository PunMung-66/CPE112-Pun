// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void traverse(node *start) {
    node *ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void insertEnd(node **head, int val) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node *current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

void deleteFirst(node **start)
{
    node *ptr;
    if (*start == NULL)
    {
        printf(" Underflow\n ");
        return;
    }
    ptr = *start;
    *start = (*start)->next;
    free(ptr);
}

void deleteLast(node **start)
{
    node *ptr, *prePtr;
    if (*start == NULL)
    {
        return;
    }
    ptr = *start;
    if (ptr->next == NULL)
    {
        *start = NULL;
        free(ptr);
        return;
    }
    while (ptr->next != NULL)
    {
        prePtr = ptr;
        ptr = ptr->next;
    }
    prePtr->next = NULL;
    free(ptr);
}

void deleteAfter(node **start, int val)
{
    node *ptr, *prePtr, *temp;
    if (*start == NULL)
    {
        return;
    }
    ptr = *start;
    prePtr = ptr;
    while (ptr->data != val)
    {
        prePtr = ptr;
        ptr = ptr->next;
    }
    temp = ptr;
    prePtr->next = ptr->next;
    free(ptr);
}

int numnode(node *start, int num)
{
    int count = 1;
    node *ptr = start;
    while ( ptr != NULL)
    {
        if (ptr->data == num)
            return count;
        count++;
        ptr = ptr->next;
    }
    return 0;
}


int main() {
    int amount, value, ref, val;
    char option = 'N';
    node *head = NULL;
    scanf("%d", &amount);
    if (amount <= 0) {
        return 0;
    }
    scanf("%d", &value);
    head = (node *)malloc(sizeof(node));
    head->data = value;
    head->next = NULL;
    for (int i = 1; i < amount; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    while (option == 'N' || option == 'L' || option == 'F') {
        scanf(" %c", &option);
        if (option == 'E')
            break;
        if (option == 'N') {
            scanf("%d", &val);
            int n = numnode(head, val);
            if (n == 0)
                continue;
            if (n == 1)
            {
                deleteFirst(&head);
                continue;
            }
            deleteAfter(&head, val);
        } else if (option == 'L' && head != NULL) {
            deleteLast(&head);
            
        } else if (option == 'F' && head != NULL) {
            deleteFirst(&head);
        }    
    }
    if (head == NULL)
        printf("none");
    else
        traverse(head);
    return 0;
}