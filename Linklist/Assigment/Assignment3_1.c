// Punnawat Mungakalarungsi 66070503436
# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int id;
    int score; 
    struct Node* next;
} node;

void insertEnd_node(node** head, int id, int score) {
    node* newNode = malloc(sizeof(node));
    newNode->id = id;
    newNode->score = score;
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

void sort_score(node** head) {
    node* current = *head;
    node* index = NULL;
    int tempId, tempScore;

    if (*head == NULL) {
        return;
    }
    else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->score > index->score) {
                    tempId = current->id;
                    tempScore = current->score;
                    current->id = index->id;
                    current->score = index->score;
                    index->id = tempId;
                    index->score = tempScore;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void sort_id(node** head) {
    node* current = *head;
    node* index = NULL;
    int tempId, tempScore;

    if (*head == NULL) {
        return;
    }
    else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->id > index->id) {
                    tempId = current->id;
                    tempScore = current->score;
                    current->id = index->id;
                    current->score = index->score;
                    index->id = tempId;
                    index->score = tempScore;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void traverse(node* start) {
    node* ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->score);
        ptr = ptr->next;
    }
}

int main()
{
    node* head = NULL;
    int amount, option;
    scanf("%d", &amount);
    for (int i = 0; i < amount; i++)
    {
        int id, score;
        scanf("%d %d", &id, &score);
        insertEnd_node(&head, id, score);
    }
    scanf("%d", &option);
    if (option == 1 || option == 0)
    {
        if (option == 0)
            sort_id(&head);
        else
            sort_score(&head);
        traverse(head);
    }
    return 0;
}