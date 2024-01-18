#include <stdio.h>
#include <stdlib.h>

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
    if (n <= 0)
        return 0;
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

int dup(int n, int inp[n])
{
    if (n <= 0)
        return 0;
    insertionSort(inp, n);
    int temp[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (inp[i] == inp[i + 1])
            temp[j++] = inp[i];
    for (int i = 0; i < j; i++)
        inp[i] = temp[i];
    inp[j] = '\0';
    j = remove_dup(j, inp);
    return (j);
}

int set_convertor(int n, int arr[n],int range[2])
{
    int count = 0, temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp >= range[0] && temp <= range[1])
            arr[i] = temp, count++;
    }
    n = count;
    return remove_dup(n, arr);
}

int check_subset(int n, int arr[n])
{
    if (n <= 0)
    {
        printf("empty\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 1;
}

void union_subset(int n, int arr1[n], int m, int arr2[m])
{
    int temp[n + m];
    int j = 0;
    for (int i = 0; i < n; i++)
        temp[j++] = arr1[i];
    for (int i = 0; i < m; i++)
        temp[j++] = arr2[i];
    temp[j] = '\0';
    j = remove_dup(j, temp);
    check_subset(j, temp);
}

void insert_subset(int n, int arr[n], int m, int arr2[m])
{
    int temp[n + m];
    int j = 0;
    for (int i = 0; i < n; i++)
        temp[j++] = arr[i];
    for (int i = 0; i < m; i++)
        temp[j++] = arr2[i];
    temp[j] = '\0';
    j = dup(j, temp);
    check_subset(j, temp);
}

void differ(int n, int arr[n], int m, int arr2[m])
{
    int temp[n + m], temp_arr1[n];
    int j = 0, k = 0, status = 0;
    for (int i = 0; i < n; i++)
        temp[j++] = arr[i];
    for (int i = 0; i < m; i++)
        temp[j++] = arr2[i];
    temp[j] = '\0';
    j = dup(j, temp);
    for (int i = 0; i < n; i++)
    {
        for (int l = 0; l < j; l++)
        {
            if (arr[i] == temp[l])
                status = 1;
        }
        if (status == 0)
            temp_arr1[k++] = arr[i];
        status = 0;
    }
    check_subset(k, temp_arr1);
}

void out_of_uni( int n, int arr[n], int range[2])
{
    int uni = range[1] - range[0] + 1;
    int temp[uni];
    int j = 0, k = 0;
    for (int i = range[0]; i <= range[1]; i++)
        temp[j++] = i;
    temp[j] = '\0';
    for (int i = 0 ; i < j; i++)
    {
        for (int l = 0; l < n; l++)
        {
            if (temp[i] == arr[l])
                k++;
        }
        if (k == 0)
            printf("%d ", temp[i]);
        k = 0;
    }
    printf("\n");
}



int main()
{
    int range[2], amount1, amount2;
    scanf("%d %d", &range[0], &range[1]);
    scanf("%d", &amount1);

    int arr1[amount1];
    amount1 = set_convertor(amount1, arr1, range);
    
    scanf("%d", &amount2);
    int arr2[amount2];
    amount2 = set_convertor(amount2, arr2, range);

    check_subset(amount1, arr1);// Line 1
    check_subset(amount2, arr2);// Line 2
    union_subset(amount1, arr1, amount2, arr2);// Line 3
    insert_subset(amount1, arr1, amount2, arr2);// Line 4
    differ(amount1, arr1, amount2, arr2);// Line 5
    differ(amount2, arr2, amount1, arr1);// Line 6
    out_of_uni(amount1, arr1, range);// Line 7
    out_of_uni(amount2, arr2, range);// Line 8
    return 0;
}