#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct
{
    node *front;
    node *rear;
    int size_max;
    int count;
} queue;

queue insertQ_C(queue, int);
queue delete_C(queue);

queue insertQ_C(queue q, int val)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = val;
    if (q.front == NULL)
    {
        q.front = ptr;
        q.rear = ptr;
        ptr->next = q.front;
    }
    else if (q.count == q.size_max)
    {
        printf("\n(* Overflow *)");
        q = delete_C(q);
        q.rear->next = ptr;
        ptr->next = q.front;
        q.rear = ptr;
        return q;
    }
    else
    {
        q.rear->next = ptr;
        ptr->next = q.front;
        q.rear = ptr;
    }
    q.count++;
    return q;
}

queue delete_C(queue q)
{
    node *ptr;
    if (q.front == NULL)
    {
        printf("\nQueue is empty");
        return q;
    }
    if (q.front == q.rear)
    {
        free(q.front);
        q.front = NULL;
        q.rear = NULL;
    }
    else
    {
        ptr = q.front;
        q.front = q.front->next;
        q.rear->next = q.front;
        free(ptr);
    }
    q.count--;
    return q;
}

int main()
{
    queue q;
    q.front = NULL;
    q.rear = NULL;
    q.count = 0;
    q.size_max = 5;
    int val;
    int choice;
    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be insert: ");
            scanf("%d", &val);
            q = insertQ_C(q, val);
            break;
        case 2:
            q = delete_C(q);
            break;
        case 3:
            while (q.front != NULL)
            {
                printf("\n%d", q.front->data);
                q = delete_C(q);
            }
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}