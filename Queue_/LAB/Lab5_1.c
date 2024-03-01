// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char song[100];
    char artist[100];
    int time;
    struct node *next;
} node;

typedef struct
{
    node *front;
    node *rear;
} queue;

// bigo O(1)
void delete_C(queue *q)
{
    node *ptr;
    if (q->front == NULL)
    {
        printf("No songs in the playlist\n");
        return;
    }
    printf("Now playing: %s ", q->front->song);
    printf("by %s\n", q->front->artist);
    ptr = q->front;
    q->front = q->front->next;
    free(ptr);
    return;
}

// bigo O(1)
void insert_C(queue *q, char *song, char *artist, int time)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    strcpy(ptr->song, song);
    strcpy(ptr->artist, artist);
    ptr->time = time;
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

// bigo O(n)
void print_sum(queue q)
{
    int sum = 0;
    node *ptr = (node *)malloc(sizeof(node));
    if (q.front == NULL)
    {
        printf("No songs in the playlist\n");
        return;
    }
    ptr = q.front;
    printf("Songs in the playlist:\n");
    while (ptr != q.rear->next)
    {
        printf("%s ", ptr->song);
        printf("by %s ", ptr->artist);
        printf("%d\n", ptr->time);
        sum += ptr->time;
        ptr = ptr->next;
    }
    printf("Remaining Time: %d\n", sum);
}

int main()
{
    char *input = (char *)malloc(4 * sizeof(char));
    queue q;
    q.front = NULL;
    q.rear = NULL;

    while (1)
    {
        scanf("%s", input);
        if (strcmp(input, "add") == 0)
        {
            int n = 0;
            char c;
            char *song = (char *)malloc(100 * sizeof(char));
            char *artist = (char *)malloc(100 * sizeof(char));
            int time;
            scanf(" %[^\n]", song);
            scanf(" %[^\n]", artist);
            scanf("%d", &time);
            insert_C(&q, song, artist, time);
        }
        else if (strcmp(input, "play") == 0)
        {
            delete_C(&q);
        }
        else if (strcmp(input, "sum") == 0)
        {
            print_sum(q);
            exit(0);
        }
    }
    return 0;
}