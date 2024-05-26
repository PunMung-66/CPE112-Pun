#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generateUniqueArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

void bubble(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void insert(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
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

void select_s(int arr[], int n)
{
    int min, i, j;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (i != min)
            swap(&arr[i], &arr[min]);
    }
}

int partition(int arr[], int low, int high)
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
        int pi = partition(arr, low, high);
        q_sort(arr, low, pi - 1);
        q_sort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
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
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void merge_s(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_s(arr, l, m);
        merge_s(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void measure_memory_usage(char algorithm, int arr[], int n)
{
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
    SIZE_T beforeSortMemUsage = pmc.PrivateUsage;
    
    Sleep(1000); // Sleep for 1 second to allow memory usage to stabilize (optional)
    switch (algorithm)
    {
    case 'b':
        bubble(arr, n);
        break;
    case 'i':
        insert(arr, n);
        break;
    case 's':
        select_s(arr, n);
        break;
    case 'q':
        q_sort(arr, 0, n - 1);
        break;
    case 'm':
        merge_s(arr, 0, n - 1);
        break;
    }
    Sleep(1000); // Sleep for 1 second to allow memory usage to stabilize (optional
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
    SIZE_T afterSortMemUsage = pmc.PrivateUsage;

    printf("Array size: %d\n", n);
    printf("Memory usage before sorting: %llu bytes\n", beforeSortMemUsage);
    printf("Memory usage after sorting: %llu bytes\n", afterSortMemUsage);
    printf("Additional memory used for sorting: %llu bytes\n\n", afterSortMemUsage - beforeSortMemUsage);
}

int main()
{
    int sample_size[] = {1000, 3000, 5000, 7000, 9000, 10000, 50000, 60000, 70000, 80000, 90000, 100000};
    char algorithm[] = {'b', 'i', 's', 'q', 'm'};
    int num_size = sizeof(sample_size) / sizeof(sample_size[0]);

    printf("+========== Random Values =========+\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nAlgorithm %c\n", algorithm[i]);
        for (int j = 0; j < num_size; j++)
        {
            int *arr = (int *)malloc(sample_size[j] * sizeof(int));
            generateUniqueArray(arr, sample_size[j]);
            measure_memory_usage(algorithm[i], arr, sample_size[j]);
            free(arr);
        }
    }

    printf("+========== Ascending Values =========+\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nAlgorithm %c\n", algorithm[i]);
        for (int j = 0; j < num_size; j++)
        {
            int *arr_asc = (int *)malloc(sample_size[j] * sizeof(int));
            for (int k = 0; k < sample_size[j]; k++)
            {
                arr_asc[k] = k;
            }
            measure_memory_usage(algorithm[i], arr_asc, sample_size[j]);
            free(arr_asc);
        }
    }

    printf("+========== Descending Values =========+\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nAlgorithm %c\n", algorithm[i]);
        for (int j = 0; j < num_size; j++)
        {
            int *arr_desc = (int *)malloc(sample_size[j] * sizeof(int));
            for (int k = 0; k < sample_size[j]; k++)
            {
                arr_desc[k] = sample_size[j] - k;
            }
            measure_memory_usage(algorithm[i], arr_desc, sample_size[j]);
            free(arr_desc);
        }
    }

    return 0;
}
