#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} node;

void traverse(node *start)
{
    node *ptr = start;
    while (ptr != NULL)
        ptr = ptr->next;
}

void printNumNode(node *start)
{
    int count = 0;
    node *ptr = start;
    while (ptr != NULL)
    {
        printf("count : %d value : %d\n", count ,ptr->data);
        count++;
        ptr = ptr->next;
    }
}

void insertEnd(node *head, int val)
{
    node *current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = (node *)malloc(sizeof(node));
    current->next->data = val;
    current->next->next = NULL;
}

void insertBegin(node **start)
{
    node *newNode;
    int val;
    printf("Enter data: ");
    scanf("%d", &val);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = *start;
    *start = newNode;
}

void insertAfter(node **start, int num)
{
    node *newNode, *ptr, *prePtr;
    int val;

    printf("Enter data value in index %d:", (num + 1));
    scanf("%d", &val);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    ptr = *start;
    prePtr = ptr;
    while (prePtr->data != num){
        prePtr = ptr;
        ptr = ptr->next;
    }
    prePtr->next = newNode;
    newNode->next = ptr;
}

void insertBefore(node **start, int num)
{
    node *newNode, *ptr, *prePtr;
    int val;

    printf("Enter data value in index %d:", (num + 1));
    scanf("%d", &val);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    ptr = *start;
    prePtr = ptr;
    while (ptr->data != num){
        prePtr = ptr;
        ptr = ptr->next;
    }
    prePtr->next = newNode;
    newNode->next = ptr;
}

int main()
{
    node *head;
    head = (node *)malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;

    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    insertBegin(&head);
    printNumNode(head);
    insertAfter(&head, 3);
    printNumNode(head);

    return 0;
}
