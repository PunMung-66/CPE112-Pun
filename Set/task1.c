#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int remove_dup(int n, int inp[n])
{
    insertionSort(inp, n);
    int temp[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (inp[i] != inp[i + 1])
            temp[j++] = inp[i];
    for (int i = 0; i < j; i++)
        inp[i] = temp[i];
    inp[j] = '\0';
    return (j);
}

int main()
{
    int n, m = 0, j = 0;
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    j = remove_dup(n, inp);
    printf("%d\n", j);
    for (int i = 0; i < j; i++)
        printf("%d ", inp[i]);
    
    return 0;
}