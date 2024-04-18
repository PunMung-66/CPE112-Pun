// Punnawat Mungkalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Heap {
    int *arr;
    int size;
};

typedef struct Heap heap;

// O(1)
heap *createHeap(int capacity) {
    heap *h = (heap *)malloc(sizeof(heap));
    h->size = 0;
    h->arr = (int *)malloc(capacity * sizeof(int));
    return h;
}

// O(log n)
void heapify(heap *root, int i) {
    // O(1)
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < root->size && root->arr[l] > root->arr[largest])
        largest = l;
    if (r < root->size && root->arr[r] > root->arr[largest])
        largest = r;
    if (largest != i) {
        int temp = root->arr[i];
        root->arr[i] = root->arr[largest];
        root->arr[largest] = temp;
        heapify(root, largest);
    }
}

// O(log n)
void insert(heap *root, int key) {
    if (root->size == 0) {
        root->arr[0] = key;
        root->size = 1;
        return;
    }
    root->arr[root->size] = key;
    int i = root->size;
    root->size++;
    // Heapify is in this line
    while (i != 0 && root->arr[i] > root->arr[(i - 1) / 2]) {
        int temp = root->arr[i];
        root->arr[i] = root->arr[(i - 1) / 2];
        root->arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// O(n)
void delete(heap *root, int key) {
    int i;
    for (i = 0; i < root->size; i++) {
        if (root->arr[i] == key)
            break;  
    }
    if (i == root->size)
        return;
    root->arr[i] = root->arr[root->size - 1];
    root->size--;
    for (int j = (root->size - 1) / 2; j >= 0; j--)
        heapify(root, j);
}

void print(heap *root) {
    for (int i = 0; i < root->size; i++)
        printf("%d ", root->arr[i]);
    printf("\n");
}

int main() {
    char opt[6];
    int value;
    heap *root = createHeap(100);

    while (1) {
        scanf(" %s", opt);
        if (strcmp(opt, "INSERT") == 0) {
            int i = 0, size, arr[100];
            char temp;
            do {
                if (scanf("%d%c", &arr[i], &temp) == EOF)
                    break;
                i++;
            } while (temp != '\n');
            size = i;
            for (i = 0; i < size; i++)
                insert(root, arr[i]);
        } else if (strcmp(opt, "DELETE") == 0) {
            int i = 0, size, arr[100];
            char temp;
            do {
                if (scanf("%d%c", &arr[i], &temp) == EOF)
                    break;
                i++;
            } while (temp != '\n');
            size = i;
            for (i = 0; i < size; i++)
                delete(root, arr[i]);
        } else if (strcmp(opt, "PRINT") == 0)
            print(root);
        else if (strcmp(opt, "EXIT") == 0)
            break;
    }
    return 0;
}
