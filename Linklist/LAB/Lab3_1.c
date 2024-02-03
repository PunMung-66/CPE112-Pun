// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insertEnd(node *head, int val)
{
    node *current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = (node *)malloc(sizeof(node));
    current->next->data = val;
    current->next->next = NULL;
}

void insertBegin(node **start, int val)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
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
    node *head;
    scanf("%d", &amount);
    if (amount <= 0)
    {
        printf("Invalid");
        return 0;
    }
    scanf("%d", &option);
    if (option == 1)
    {
        scanf("%d", &value);
        head = (node *)malloc(sizeof(node));
        head->data = value;
        head->next = NULL;
        for (int i = 1; i < amount; i++)
        {
            scanf("%d", &value);
            insertBegin(&head, value);
        }
    } 
    else if (option == 2)
    {
        scanf("%d", &value);
        head = (node *)malloc(sizeof(node));
        head->data = value;
        head->next = NULL;
        for (int i = 1; i < amount; i++)
        {
            scanf("%d", &value);
            insertEnd(head, value);
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