// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

void insertEnd_cir(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = data;
    new_node->next = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = new_node; 
        *head_ref = new_node;
        return;
    }

    while (last->next != *head_ref)
        last = last->next;

    last->next = new_node;
    new_node->next = *head_ref;
}

void traverse_circle(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

int len_cir(struct Node* head, int num) {
    struct Node* temp = head;
    int count = 0;
    if (head != NULL) {
        do {
            count++;
            if (temp->data == num)
                return count;
            temp = temp->next;
        } while (temp != head);
    }
    //printf("index : %d\n", count);
    return count;
}

void Josephus(struct Node** head, int k) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    int count = 0;
    while (current->next != current) {
        count++;
        if (count == k) {
            prev->next = current->next;
            free(current);
            current = prev->next;
            count = 0;
        } else {
            prev = current;
            current = current->next;
        }
    }
    printf("%d", current->data);
}

int main()
{
    int n, s;
    scanf("%d", &n);
    scanf("%d", &s);
    node* head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertEnd_cir(&head, data);
    }
    Josephus(&head, s);
    return 0;
}