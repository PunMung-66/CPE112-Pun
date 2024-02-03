// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

void insertEnd_cir(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // To traverse the list

    new_node->data = data;
    new_node->next = *head_ref; // New node points to head initially

    // If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        new_node->next = new_node; // Circular reference to itself
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse to the last node
    while (last->next != *head_ref)
        last = last->next;

    // Update the next pointer of the last node
    last->next = new_node;

    // Make the new node the new last node by pointing it to the head
    new_node->next = *head_ref;
}

void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL)
        return;

    struct Node *current = *head_ref, *prev = NULL;

    // If the node to be deleted is the head
    if (current->data == key) {
        while (current->next != *head_ref)
            current = current->next;
        *head_ref = (*head_ref)->next;
        current->next = *head_ref;
        free(current);
        return;
    }

    // Find the previous node of the node to be deleted
    while (current->next != *head_ref && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the node to be deleted was not found
    if (current->data != key) {
        return;
    }

    // Unlink the node from the list
    prev->next = current->next;
    free(current);
}


void deleteBegin_cir(struct Node** head_ref) {
    if (*head_ref == NULL)
        return;

    struct Node* last = *head_ref;
    while (last->next != *head_ref)
        last = last->next;

    if (*head_ref == last) { // If only one node
        free(*head_ref);
        *head_ref = NULL;
    } else {
        struct Node* temp = *head_ref;
        last->next = (*head_ref)->next;
        *head_ref = (*head_ref)->next;
        free(temp);
    }
}

void deleteLast_cir(struct Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == *head_ref)
        return;

    struct Node *current = *head_ref, *prev = NULL;
    while (current->next != *head_ref) {
        prev = current;
        current = current->next;
    }
    if (prev != NULL) {
        prev->next = *head_ref;
        free(current);
    }
}




void traverse_cir(struct Node* head) {
    if (head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

int numnode(struct Node* head, int num) {
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

int main()
{
    char option = 'I', count = 0;
    node *head = NULL;
    while (option == 'I' || option == 'D')
    {
        scanf(" %c", &option);
        if (option == 'I')
        {
            count++;
            int data;
            scanf("%d", &data);
            insertEnd_cir(&head, data);
        }
        if (option == 'D')
        {
            int data;
            scanf("%d", &data);
            //printf("data : %d\n", data);
            if (numnode(head, data) == 1)
                deleteBegin_cir(&head);
            else if (numnode(head, data) == count)
                deleteLast_cir(&head);
            else
                deleteNode(&head, data);
        }
    }
    traverse_cir(head);
    return 0;
}