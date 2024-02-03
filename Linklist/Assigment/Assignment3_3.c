// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

void insertEnd(ListNode **head, int val)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    ListNode *current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

void traverse(ListNode *head)
{
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

void swop(ListNode **head, int index_s, int index_l)
{
    ListNode *current = *head;
    ListNode *temp = NULL;
    ListNode *temp2 = NULL;
    int count = 0;
    while (current != NULL)
    {
        count++;
        if (count == index_s)
        {
            temp = current;
            //printf("index_s : %d\n", temp->val);
        }
        if (count == index_l)
        {
            temp2 = current;
            //printf("index_l : %d\n", temp2->val);
            break;
        }
        current = current->next;
    }
    int tempVal = temp->val;
    temp->val = temp2->val;
    temp2->val = tempVal;
}

void reverse(ListNode **head, int index_s, int index_l)
{
    int size = index_l - index_s + 1;
    int	m = size;
	int n = ceil(size / 2);

    while (n > 0)
    {
        swop(head, index_s, index_s + m - 1);
        index_s++;
        m -= 2;
        n--;
    }
}
int main()
{
    ListNode *head = NULL;
    char *option = (char *)malloc(3 * sizeof(char));
    while (option != "END")
    {
        scanf("%s", option);
        if (strcmp(option, "END") == 0)
            break;
        int data = atoi(option);
        insertEnd(&head, data);
    }
    int index_s, index_l;
    scanf("%d", &index_s);
    scanf("%d", &index_l);
    reverse(&head, index_s, index_l);
    traverse(head);

    return 0;
}
