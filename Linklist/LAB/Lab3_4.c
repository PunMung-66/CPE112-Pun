// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct sch {
    int b;
    int a;
    struct sch* next;
} sch;

void insertEnd(node** head, int val) {
    node* newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node* current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

void insertEnd_sch(sch** head, int b, int a) {
    sch* newNode = malloc(sizeof(sch));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->b = b;
    newNode->a = a;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    sch* current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

void insertBegin(node** start, int val) {
    node* newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->next = *start;
    *start = newNode;
}

void traverse(node* start) {
    node* ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int *mix_num(node **start, int num)
{
    int a = 0, b = 0, count = 0;
    node *ptr, *prePtr;
    ptr = *start;
    prePtr = ptr;
    //printf("num : %d\n", num);
    if (prePtr->data == num)
        b = -9999;
    while (ptr->data != num){
        if (ptr->next->next == NULL)
            a = -9999;
        prePtr = ptr;
        ptr = ptr->next;
    }
    if (b != -9999)
        b = prePtr->data;
    if (a != -9999)
        a = ptr->next->data;
    int *arr = (int *)calloc(2 , sizeof(int));
    *arr = b;
    *(arr + 1) = a;
    // printf("in b : %d\n", b);
    // printf("in a : %d\n", a);
    return  arr;
}

void deleteAfter(node** start, int val) {
    node* ptr;
    node* prePtr;
    node* temp;

    if (*start == NULL)
        return;

    ptr = *start;
    prePtr = ptr;

    while (ptr->data != val) {
        prePtr = ptr;
        ptr = ptr->next;
    }

    temp = ptr;
    prePtr->next = ptr->next;
    free(ptr);
}

void deleteFirst(node** start) {
    node* ptr;
    if (*start == NULL) {
        printf(" Underflow\n ");
        return;
    }
    ptr = *start;
    *start = (*start)->next;
    free(ptr);
}

void deleteLast(node** start) {
    node* ptr;
    node* prePtr;
    if (*start == NULL)
        return;
    ptr = *start;
    if (ptr->next == NULL) {
        *start = NULL;
        free(ptr);
        return;
    }
    while (ptr->next != NULL) {
        prePtr = ptr;
        ptr = ptr->next;
    }
    prePtr->next = NULL;
    free(ptr);
}

int numnode(node* start, int num) {
    int count = 1;
    node* ptr = start;
    while (ptr != NULL) {
        if (ptr->data == num)
            return count;
        count++;
        ptr = ptr->next;
    }
    return 0;
}

int main() {
    int amount, value, ref, val, status_sch = 0;
    char option[4] = "ADD"; // Define as a character array instead of dynamic allocation
    node* head = NULL;
    node* head_re = NULL;
    sch* sch_head = NULL;

    while (strcmp(option, "ADD") == 0 || strcmp(option, "DEL") == 0 || strcmp(option, "SCH") == 0) {
        scanf("%s", option);
        if (strcmp(option, "END") == 0)
            break;
        if (strcmp(option, "ADD") == 0) {
            scanf("%d", &value);
            if (head == NULL || head_re == NULL) {
                head = malloc(sizeof(node));
                head->data = value;
                head->next = NULL;
                head_re = malloc(sizeof(node));
                head_re->data = value;
                head_re->next = NULL;
            } else {
                insertEnd(&head, value);
                insertBegin(&head_re, value);
            }

        } else if (strcmp(option, "DEL") == 0) {
            scanf("%d", &ref);
            if (head == NULL || head_re == NULL || numnode(head, ref) == 0)
                continue;
            if (numnode(head, ref) == 1)
                deleteFirst(&head);
            else
                deleteAfter(&head, ref);
            if (numnode(head_re, ref) == 1)
                deleteFirst(&head_re);
            else
                deleteAfter(&head_re, ref);
        } else if (strcmp(option, "SCH") == 0) {
            scanf("%d", &val);
            if (head == NULL || numnode(head, val) == 0) {
                insertEnd_sch(&sch_head, -9998, -9998);
                continue;
            }
            int* arr = mix_num(&head, val);
            int b = arr[0];
            int a = arr[1];
            insertEnd_sch(&sch_head, b, a);
            free(arr); // Free the allocated memory
        }
    }

    if (sch_head != NULL) {
        sch* ptr = sch_head;
        while (ptr != NULL) {
            if (ptr->b == -9998 && ptr->a == -9998) {
                printf("none\n");
            } else {
                if (ptr->b == -9999)
                    printf("NULL ");
                else
                    printf("%d ", ptr->b);
               
                if (ptr->a == -9999)
                    printf("NULL\n");
                else
                    printf("%d\n", ptr->a);
            }
            ptr = ptr->next;
        }
    }
    if (head == NULL)
        printf("none\n");
    if (head_re == NULL)
        printf("none");
    else {
        traverse(head);
        printf("\n");
        traverse(head_re);
    }

    // Freeing dynamically allocated memory
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }
    while (head_re != NULL) {
        node* temp = head_re;
        head_re = head_re->next;
        free(temp);
    }
    while (sch_head != NULL) {
        sch* temp = sch_head;
        sch_head = sch_head->next;
        free(temp);
    }

    return 0;
}
