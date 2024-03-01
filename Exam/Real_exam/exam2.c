// Problem 2: Palindrome Creator 
// 66070503436 Punnawat Mungkalarungsi

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
} node;

typedef struct
{
    node *front;
    node *rear;
} queue;

void push(node **top, char data)
{
    // Big O(1)
    node *newNode = malloc(sizeof(node)); // allocate memory for the new node
    newNode->data = data; // set the data of the new node
    newNode->next = *top; // set the next of the new node to the top
    *top = newNode; // set the top to the new node
}

char pop_stack(node **top)
{
    // Big O(1)
    if (*top == NULL)// if the stack is empty
    {
        return '\0';
    }
    node *temp = *top;
    *top = (*top)->next; // set the top to the next of the top
    char data = temp->data;
    free(temp);
    return data;
}


void initQueue(queue *q)
{
    // Big O(1)
    q->front = NULL; // set the front of the queue to NULL
    q->rear = NULL; // set the rear of the queue to NULL
}

void insert_C(queue *q, char letter)
{
    // Big O(1)
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = letter;
    ptr->next = NULL;
    if (q->front == NULL) // if the queue is empty
    {
        q->front = ptr;
        q->rear = ptr;
    }
    else // if the queue is not empty
    {
        q->rear->next = ptr;
        q->rear = ptr;
    }
    return;
}

int print_dequeue(queue *q)
{
    // Big O(1)
    node *ptr;
    if (q->front == NULL) // if the queue is empty
    {
        return -1;
    }
    ptr = q->front;
    printf("%c", ptr->data); // print the data of the front
    q->front = q->front->next; // set the front to the next of the front (next element in the queue)
    free(ptr);
    return 0;
}

int check_lastchar_dup(char *input)
{
    // Big O(n)
    int i = 0;
    while (input[i] != '\0') // loop through the string
    {
        i++;
    }
    i--; // i in the last character of the string
    for (int j = 0; j < i; j++) // loop through the string
    {
        if (input[j] == input[i]) // if the last character is duplicated
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i = 0;
    char input[1000];
    scanf("%[^\n]", input);
    node *stack2 = NULL;
    queue q;
    initQueue(&q);
    for (i = 0; input[i] != '\0'; i++)
    {
        insert_C(&q, input[i]); // insert the character to the queue
        if (input[i + 1] != '\0')
        {
           push(&stack2, input[i]); // push the character to the stack
        }
    }
    i--; // i in the last character of the string
    while (q.front != NULL)
    {
        print_dequeue(&q); // print the original string
    }
    if (check_lastchar_dup(input) == 1) // if the last character is duplicated
    {
        char temp;
        while ( temp != input[i])
        {
            temp = pop_stack(&stack2); // pop the stack
        }
    }
    while (stack2 != NULL)
    {
        printf("%c", pop_stack(&stack2)); // print the reversed string with out the last character
    }
    return 0;
}
