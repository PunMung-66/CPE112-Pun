#include <stdio.h>

void swap( int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble ( int arr[], int n)
{
    int i, j;

    for ( i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if ( arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j+ 1]);
        }
    }
}

void insert( int arr[], int n)
{
    int i, j, key;
    for ( i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void select( int arr[], int n)
{
    int min, i, j;

    for ( i = 0; i < n -1; i++)
    {
        min = i;
        for ( j = i + 1; j < n; j++)
        {
            if ( arr[j] < arr[min])
                min = j;
        }

        if ( i != min)
            swap(&arr[i], &arr[min]);
    }
}

void print ( int arr[], int n)
{
    for ( int i = 0; i < n ; i++)
        printf("%d ", arr[i]);

}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);

    select(arr, n);

    print( arr, n);
    return 0;
}