// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    char letter;
    int priority;
    struct node *next;
} node;

typedef struct
{
    node *front;
    node *rear;
} queue;

void initQueue(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void insert_C(queue *q, char letter, int priority)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->letter = letter;
    ptr->priority = priority;
    ptr->next = NULL;
    if (q->front == NULL)
    {
        q->front = ptr;
        q->rear = ptr;
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
    }
    return;
}

int print_dequeue(queue *q)
{
    node *ptr;
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    ptr = q->front;
    printf("%c", ptr->letter);
    q->front = q->front->next;
    free(ptr);
    return 0;
}


int main()
{
    queue q3;
    queue q2;
    queue q;
    initQueue(&q3);
    initQueue(&q2);
    initQueue(&q);
    while (1)
    {
        char letter;
        scanf("%c", &letter);
        if (letter == '\n')
            break;
        int priority;
        if (isalpha(letter))
        {
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
                letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U')
            {
                priority = 3; // Vowels
            }
            else
            {
                priority = 1; // Consonants
            }
        }
        else if (isspace(letter))
        {
            priority = 2; // Whitespace
        }
        else
        {
            priority = 2; // Other characters
        }
        if (priority == 1)
            insert_C(&q, letter, priority);
        else if (priority == 2)
            insert_C(&q2, letter, priority);
        else
            insert_C(&q3, letter, priority);
    }
    while (q3.front != NULL)
    {
        print_dequeue(&q3);
    }
    while (q2.front != NULL)
    {
        print_dequeue(&q2);
    }
    while (q.front != NULL)
    {
        print_dequeue(&q);
    }
    
    return 0;
}