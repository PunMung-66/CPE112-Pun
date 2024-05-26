#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap( int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generateUniqueArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1; // Populate the array with unique numbers
    }
    // Shuffle the array to randomize the order
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
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

int partitian(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void q_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitian(arr, low, high);
        q_sort(arr, low, pi - 1);
        q_sort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + j + 1];
    i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++, k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++, k++;
    }
}

void merge_s(int arr[], int l, int r)
{
    if ( l < r)
    {
        int m = l + (r - l)/2;
        merge_s(arr, l, m);
        merge_s(arr, m + 1, r);
        merge(arr, l ,m ,r);
    }
}

int main()
{
    int sample_size[] = {1000,3000,5000,7000,9000,10000,50000,60000,70000,80000,90000, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000};
    char algorithm[] = {'b', 'i', 's', 'q', 'm'};
    int num_size = sizeof(sample_size) / sizeof(sample_size[0]);
    int k;

    printf("+========== Random Values ========= +\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nAlgorithm %c\n", algorithm[i]);
        for (int j = 0; j < num_size; j++)
        {
            int arr[sample_size[j]];
            generateUniqueArray(arr, sample_size[j]);

            clock_t start, end;
            double time;
            start = clock();
            switch (algorithm[i])
            {
            case 'b':
                bubble(arr, sample_size[j]);
                break;
            case 'i':
                insert(arr, sample_size[j]);
                break;
            case 's':
                select(arr, sample_size[j]);
                break;
            case 'q':
                q_sort(arr, 0, sample_size[j] - 1);
                break;
            case 'm':
                merge_s(arr, 0, sample_size[j] - 1);
                break;
            }
            end = clock();
            time = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("%f\n", time);
        }
    }

    printf("+========== Ascending Values ========= +\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nAlgorithm %c\n", algorithm[i]);
        for (int j = 0; j < num_size; j++)
        {
            int arr_asc[sample_size[j]];
            k = 0;
            while (k < sample_size[j])
            {
                arr_asc[k] = k;
                k++;
            }

            clock_t start, end;
            double time;
            start = clock();
            switch (algorithm[i])
            {
            case 'b':
                bubble(arr_asc, sample_size[j]);
                break;
            case 'i':
                insert(arr_asc, sample_size[j]);
                break;
            case 's':
                select(arr_asc, sample_size[j]);
                break;
            case 'q':
                q_sort(arr_asc, 0, sample_size[j] - 1);
                break;
            case 'm':
                merge_s(arr_asc, 0, sample_size[j] - 1);
                break;
            }
            end = clock();
            time = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("%f\n", time);
        }
    }

    printf("+========== Descending Values ========= +\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nAlgorithm %c\n", algorithm[i]);
        for (int j = 0; j < num_size; j++)
        {
            int arr_desc[sample_size[j]];
            k = 0;
            while (k < sample_size[j])
            {
                arr_desc[k] = sample_size[j] - k;
                k++;
            }

            clock_t start, end;
            double time;
            start = clock();
            switch (algorithm[i])
            {
            case 'b':
                bubble(arr_desc, sample_size[j]);
                break;
            case 'i':
                insert(arr_desc, sample_size[j]);
                break;
            case 's':
                select(arr_desc, sample_size[j]);
                break;
            case 'q':
                q_sort(arr_desc, 0, sample_size[j] - 1);
                break;
            case 'm':
                merge_s(arr_desc, 0, sample_size[j] - 1);
                break;
            }
            end = clock();
            time = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("%f\n", time);
        }
    }

    return 0;
}