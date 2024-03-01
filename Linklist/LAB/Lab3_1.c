// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insertEnd(node **start, int val)
{
    node *newNode, *ptr;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    if (*start == NULL)
    {
        *start = newNode;
        return;
    }
    ptr = *start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
}

void insertBegin(node **start, int val)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    if (*start == NULL)
    {
        newNode->data = val;
        newNode->next = NULL;
        *start = newNode;
        return;
    }
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

int main()
{
    int amount, value, option;
    node *head = NULL;
    scanf("%d", &amount);
    if (amount <= 0)
    {
        printf("Invalid");
        return 0;
    }
    scanf("%d", &option);
    if (option == 1 || option == 2)
    {
        for (int i = 0; i < amount; i++)
        {
            scanf("%d", &value);
            if (option == 1)
                insertBegin(&head, value);
            else
                insertEnd(&head, value);
        }
    }
    else
    {
        printf("Invalid");
        return 0;
    }
    traverse(head);
    return 0;
}