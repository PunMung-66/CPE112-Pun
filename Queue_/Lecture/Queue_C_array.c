#include <stdio.h>

#define MAX_SIZE 5

void delete_arr(int *n, int *arr)
{
    if (*n == 0)
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\n%d deleted\n", arr[0]);
    for (int i = 0; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[*n - 1] = '\0';
    (*n)--;
}

void insert_arr(int *n, int *arr)
{
    int val;
    printf("\nEnter the value to insert: ");
    scanf("%d", &val);
    (*n)++;
    if (*n > MAX_SIZE)
    {
        arr[*n - 1] = '\0';
        *n = *n % MAX_SIZE;
        arr[*n - 1] = val;
        return;
    }
    arr[*n] = '\0';
    arr[*n - 1] = val;
    printf("\nValue inserted %d\n", *n);
}

void print_arr(int n, int *arr)
{
    printf("\nQueue elements: ");
    while (*arr != '\0')
    {
        printf("%d ", *arr++);
    }
    
    printf("\n");
}

int main()
{
    int choice, n = 0;
    int arr[MAX_SIZE];
    do
    {
        printf("\n1. Insert element into queue");
        printf("\n2. Delete element from queue");
        printf("\n3. Print queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_arr(&n, arr);
            break;
        case 2:
            delete_arr(&n, arr);
            break;
        case 3:
            print_arr(n, arr);
            break;
        }
    } while (choice != 4);
    return 0;
}
// 1 1 1 2 1 3 1 4 1 5 