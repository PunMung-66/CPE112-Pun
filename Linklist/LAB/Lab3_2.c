// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insertEnd(node **head, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    node *current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

void insertBegin(node **start, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = *start;
    *start = newNode;
}

void traverse(node *start)
{
    node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void insertAfter(node *prePtr, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = prePtr->next;
    prePtr->next = newNode;
}

void insertBefore(node **start, node *prePtr, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    if (prePtr == *start)
    {
        newNode->next = *start;
        *start = newNode;
    }
    else
    {
        node *ptr = *start;
        while (ptr->next != prePtr)
            ptr = ptr->next;
        ptr->next = newNode;
        newNode->next = prePtr;
    }
}

int main()
{
    int amount, value, ref, val;
    char option = 'A';
    node *head = NULL;
    scanf("%d", &amount);
    if (amount <= 0)
    {
        return 0;
    }
    scanf("%d", &value);
    head = (node *)malloc(sizeof(node));
    head->data = value;
    head->next = NULL;
    for (int i = 1; i < amount; i++)
    {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    while (option == 'A' || option == 'B')
    {
        scanf(" %c", &option);
        if (option != 'A' && option != 'B') // Exit loop if option is neither 'A' nor 'B'
            break;
        scanf("%d %d", &ref, &val);
        node *prePtr = head;
        while (prePtr != NULL && prePtr->data != ref)
            prePtr = prePtr->next;
        if (prePtr == NULL)
            continue;
        if (option == 'A' && prePtr->next == NULL) // If prePtr is the last node
            insertEnd(&head, val);
        else if (option == 'A')
            insertAfter(prePtr, val);
        if (option == 'B' && prePtr == head) // If prePtr is the first node
            insertBegin(&head, val);
        else if (option == 'B')
            insertBefore(&head, prePtr, val);
        amount++;
    }
    traverse(head);
    return 0;
}
