// Punnawat Mungkalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Structure to represent a node in the binary tree
typedef struct {
    int data;
} Node;

// Array to store the binary tree
Node tree[MAX_SIZE];
int treeSize = 0; // Variable to hold the size of the tree

void insertRoot(int data) {
    if (tree[0].data != -999) {
        printf("cannot create duplicated root\n");
        return;
    }
    tree[0].data = data;
}

// Function to insert a node on the left
void insertLeft(int parentIndex, int data) {
    int leftChildIndex = 2 * parentIndex + 1;
    if (leftChildIndex >= treeSize) {
        printf("overflow\n");
        return;
    }
    if (tree[leftChildIndex].data != -999) {
         printf("node already presented\n");
    }
    else {
        tree[leftChildIndex].data = data;
    }
}

// Function to insert a node on the right
void insertRight(int parentIndex, int data) {
    int rightChildIndex = 2 * parentIndex + 2;
    if (rightChildIndex >= treeSize) {
        printf("overflow\n");
        return;
    }
    if (tree[rightChildIndex].data != -999) {
         printf("node already presented\n");
    }
    else {
        tree[rightChildIndex].data = data;
    }
}

// Function to find a node with given data
int findNode(int data) {
    for (int i = 0; i < treeSize; i++) {
        if (tree[i].data == data) {
            return i;
        }
    }
    return -1;
}

void printTree() {
    for (int i = 0; i < treeSize; i++) {
        if (tree[i].data != -999)
            printf("%d ", tree[i].data);
        else
            printf("null ");
    }
}

int main() {
    scanf("%d", &treeSize);
    int data = -999, root = 0;
    for (int i = 0; i < treeSize; i++) {
        scanf("%d", &data);
        tree[i].data = data;
    }
    char opt[5];
    while (1)
    {
        scanf(" %s", &opt);
        if (strcmp(opt, "ROOT") == 0)
        {
            scanf("%d", &data);
            insertRoot(data);
        }
        else if (strcmp(opt, "INSL") == 0)
        {
            scanf("%d", &root);
            scanf("%d", &data);
            int index = findNode(root);
            if (index == -1) {
                printf("not found\n");
            } else {
                insertLeft(index, data);
            }
        }
        else if (strcmp(opt, "INSR") == 0)
        {
            scanf("%d", &root);
            scanf("%d", &data);
            int index = findNode(root);
            if (index == -1) {
                printf("not found\n");
            } else {
                insertRight(index, data);
            }
        }
        else if (strcmp(opt, "END") == 0)
        {
            printTree();
            break;
        }
    }
    return 0;
}
