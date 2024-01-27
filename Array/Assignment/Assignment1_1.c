// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>

int min(int *num, int amount)
{
    int index = 0;
    for (int i = 0; i < amount; i++)
        if(*(num + index) > *(num + i))
            index = i;
    return index;
}

int minJumps(int arr[], int start, int end)
{
    if (start > end)
        return -1000;
    if (start == end)
        return 0;
    if (arr[start] == 0 && start != end)
        return -1000;
    if (arr[start] == 0)
        return 0;
    return 1 + minJumps(arr, start + arr[start], end);
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        return 0;
    }
    int arr[n];
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int start = 0, end = n - 1;
    int value = (minJumps(arr, start, end));

    if (value < 0)
        printf("Not Possible");
    else
        printf("%d", value);
    //minJumps(start, end) = 1 + Min(minJumps(k, end))
    return 0;
}