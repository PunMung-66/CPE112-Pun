// Punnawat Mungkalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void insertRoot(int tree[], int treeSize, int data) {
    if (tree[0] != -999) {
        printf("cannot create duplicated root\n");
        return;
    }
    tree[0] = data;
}

void insertLeft(int tree[], int treeSize, int parentIndex, int data) {
    int leftChildIndex = 2 * parentIndex + 1;
    if (leftChildIndex >= treeSize) {
        printf("overflow\n");
        return;
    }
    if (tree[leftChildIndex] != -999) {
         printf("node already presented\n");
    }
    else {
        tree[leftChildIndex] = data;
    }
}

void insertRight(int tree[], int treeSize, int parentIndex, int data) {
    int rightChildIndex = 2 * parentIndex + 2;
    if (rightChildIndex >= treeSize) {
        printf("overflow\n");
        return;
    }
    if (tree[rightChildIndex] != -999) {
         printf("node already presented\n");
    }
    else {
        tree[rightChildIndex] = data;
    }
}

int findNode(int tree[], int treeSize, int data) {
    for (int i = 0; i < treeSize; i++) {
        if (tree[i] == data) {
            return i;
        }
    }
    return -1;
}

void printTree(int tree[], int treeSize) {
    for (int i = 0; i < treeSize; i++) {
        if (tree[i] != -999)
            printf("%d ", tree[i]);
        else
            printf("null ");
    }
}

int main() {
    int treeSize;
    scanf("%d", &treeSize);
    int tree[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -999; // Initialize tree nodes
    }

    int data = -999, root = 0;
    for (int i = 0; i < treeSize; i++) {
        scanf("%d", &data);
        tree[i] = data;
    }
    char opt[5];
    while (1)
    {
        scanf(" %s", opt);
        if (strcmp(opt, "ROOT") == 0)
        {
            scanf("%d", &data);
            insertRoot(tree, treeSize, data);
        }
        else if (strcmp(opt, "INSL") == 0)
        {
            scanf("%d", &root);
            scanf("%d", &data);
            int index = findNode(tree, treeSize, root);
            if (index == -1) {
                printf("not found\n");
            } else {
                insertLeft(tree, treeSize, index, data);
            }
        }
        else if (strcmp(opt, "INSR") == 0)
        {
            scanf("%d", &root);
            scanf("%d", &data);
            int index = findNode(tree, treeSize, root);
            if (index == -1) {
                printf("not found\n");
            } else {
                insertRight(tree, treeSize, index, data);
            }
        }
        else if (strcmp(opt, "END") == 0)
        {
            printTree(tree, treeSize);
            break;
        }
    }
    return 0;
}
