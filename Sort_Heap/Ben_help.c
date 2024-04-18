#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void createHeap(int* Heap_Tree, int* root) {
    *root = -1;
}

void heapify (int* Heap_Tree, int root, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left <= root && Heap_Tree[left] < Heap_Tree[smallest]) {
        smallest = left;
    }

    if (right <= root && Heap_Tree[right] < Heap_Tree[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        int temp = Heap_Tree[i];
        Heap_Tree[i] = Heap_Tree[smallest];
        Heap_Tree[smallest] = temp;
        heapify(Heap_Tree, root, smallest);
    }
}

void insertNode(int data, int* Heap_Tree, int* root) {
    if (*root == MAX - 1) {
        return;
    }

    *root += 1;
    int i = *root;

    while (i > 0 && data < Heap_Tree[(i - 1) / 2]) {
        Heap_Tree[i] = Heap_Tree[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    Heap_Tree[i] = data;
}

void deleteNode(int data, int* Heap_Tree, int* root) {
    if (*root == -1) {
        return;
    }

    int i = 0;

    while (i <= *root && Heap_Tree[i] != data) {
        i++;
    }

    if (i > *root) {
        return;
    }
    if (i == *root) {
        *root -= 1;
        return;
    }

    Heap_Tree[i] = Heap_Tree[*root];
    *root -= 1;

    heapify(Heap_Tree, *root, i);
}

void printHeap(int* Heap_Tree, int root) {
    if (root == -1) {
        return;
    }
    for (int i = 0; i <= root; i++) {
        printf("%d ", Heap_Tree[i]);
    }
    printf("\n");
}

int main() {
    char choice[7];
    int data;
    int root;
    int Heap_Tree[MAX];

    createHeap(Heap_Tree, &root);

    while (1) {
        scanf("%s", choice);
        if (strcmp(choice, "INSERT") == 0) {
            while (scanf("%d", &data) == 1) {
                insertNode(data, Heap_Tree, &root);
            }
        }
        else if (strcmp(choice, "DELETE") == 0) {
            while (scanf("%d", &data) == 1) {
                deleteNode(data, Heap_Tree, &root);
            }
        }
        else if (strcmp(choice, "PRINT") == 0) {
            printHeap(Heap_Tree, root);
        }
        else if (strcmp(choice, "EXIT") == 0) {
            break;
        }
    }

    return 0;
}