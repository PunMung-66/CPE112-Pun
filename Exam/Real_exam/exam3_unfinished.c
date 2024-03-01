// Problem 3: Fourris Wheel
// 66070503436 Punnawat Mungkalarungsi

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct
{
    node *front;
    node *rear;
} queue;

void initQueue(queue *q)
{
    // Big O(1)
    q->front = NULL; // set the front of the queue to NULL
    q->rear = NULL;  // set the rear of the queue to NULL
}

void insert_C(queue *q, int data)
{
    // Big O(1)
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    if (q->front == NULL) // if the queue is empty
    {
        q->front = ptr;
        q->rear = ptr;
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
    }
}

int delete_C(queue *q)
{
    // Big O(1)
    node *ptr;
    int data;
    if (q->front == NULL)
    {
        return -1;
    }
    ptr = q->front;
    data = ptr->data;
    q->front = q->front->next;
    free(ptr);
    return data;
}

int print_queue(queue q)
{
    // Big O(n)
    node *ptr;
    int count = 0;
    ptr = q.front;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("\n");
    return count;
}

int main()
{
    queue q;
    queue q2;
    queue q3;
    queue q4;
    queue q_p;
    initQueue(&q);
    initQueue(&q2);
    initQueue(&q3);
    initQueue(&q4);
    initQueue(&q_p);
    int n, m, sum = 0, count = 0;
    int seat = 4;
    scanf("%d", &n);
    m = n;
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        insert_C(&q, data);
        insert_C(&q2, data);
        insert_C(&q3, data);
        insert_C(&q4, data);
    }
    // sum 4
    for (int i = 0; i < n; i++)
    {
        int data = delete_C(&q);
        sum += data;
        count++;
        insert_C(&q_p, data);
        if (sum == 4)
        {
            print_queue(q_p);
            initQueue(&q_p);
            sum = 0;
        }
        if (sum > 4)
        {
            initQueue(&q_p);
            sum = 0;
            count = 0;
        }
    }
    printf("m = %d\n", m);
    if (m == 0)
    {
        return 0;
    }
    sum = 0;
    count = 0;
    initQueue(&q_p);
    // sum 3
    for (int i = 0; i < n; i++)
    {
        int data = delete_C(&q2);
        sum += data;
        insert_C(&q_p, data);
        if (sum == 3)
        {
            int temp = print_queue(q_p);
            m = m - temp;
            initQueue(&q_p);
            sum = 0;
        }
        if (sum > 3)
        {
            initQueue(&q_p);
            sum = 0;
        }
    }
    if (m == 0)
    {
        return 0;
    }
    sum = 0;
    initQueue(&q_p);
    // sum 2
    for (int i = 0; i < n; i++)
    {
        int data = delete_C(&q3);
        sum += data;
        insert_C(&q_p, data);
        if (sum == 2)
        {
            m = m - print_queue(q_p);
            initQueue(&q_p);
            sum = 0;
        }
        if (sum > 2)
        {
            initQueue(&q_p);
            sum = 0;
        }
    }
    if (m == 0)
    {
        return 0;
    }
    sum = 0;
    initQueue(&q_p);
    // sum 1
    for (int i = 0; i < n; i++)
    {
        int data = delete_C(&q4);
        sum += data;
        insert_C(&q_p, data);
        if (sum == 1)
        {
            m = m - print_queue(q_p);
            initQueue(&q_p);
            sum = 0;
        }
        if (sum > 1)
        {
            initQueue(&q_p);
            sum = 0;
        }
    }

    return 0;
}
