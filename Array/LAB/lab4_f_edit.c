// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

int deleteArray(int* arr, int size, int index)
{
    int i;
    for (i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return size - 1;

}

int mergeArray(int* arr1, int size1, int* arr2, int size2)
{
    int i, j;
    for (i = size1, j = 0; j < size2; i++, j++)
    {
        arr1[i] = arr2[j];
    }
    return size1 + size2;
}

int insertArray(int* arr, int size, int index, int value)
{
    int i;
    for (i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
    return size + 1;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n, m, new_n, index, value, del, merge_size;
    scanf("%d", &n);
    int *arr1 = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
        scanf("%d", (arr1 + i));
    scanf("%d", &m);
    int *arr2 = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) 
        scanf("%d", (arr2 + i));
    scanf("%d", &index);
    scanf("%d", &value);
    scanf("%d", &del);
    if ( index > n || index < 0)
        printf("Index out of bounds\n");
    else
    {
        new_n = insertArray(arr1, n, index, value);
        printArray(arr1, new_n);
        printf("\n");
    }
    if ( del > n || del < 0)
        printf("Index out of bounds\n");
    else
    {
        new_n = deleteArray(arr1, new_n, del);
        printArray(arr1, new_n);
        printf("\n"); 
    }
    arr1 = (int*)realloc(arr1, (new_n + m) * sizeof(int));
    merge_size = mergeArray(arr1, new_n, arr2, m);
    printArray(arr1, merge_size);
    return 0;
}