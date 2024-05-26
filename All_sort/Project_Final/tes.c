#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <psapi.h>

void merge(int* arr, int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < left_size) {
        arr[k++] = left[i++];
    }
    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int* arr, int size) {
    if (size <= 1) {
        return;
    }
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}

int main() {
    const int size = 60000; // Array size (10 million elements)
    int* arr = malloc(size * sizeof(int));

    // Initialize array with random values
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }

    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
    SIZE_T beforeSortMemUsage = pmc.PrivateUsage;

    // Sort the array using merge sort
    mergeSort(arr, size);

    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
    SIZE_T afterSortMemUsage = pmc.PrivateUsage;

    printf("Memory usage before sorting: %llu bytes\n", beforeSortMemUsage);
    printf("Memory usage after sorting: %llu bytes\n", afterSortMemUsage);
    printf("Additional memory used for sorting: %llu bytes\n", afterSortMemUsage - beforeSortMemUsage);

    free(arr);
    return 0;
}