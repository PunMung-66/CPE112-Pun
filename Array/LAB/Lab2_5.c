// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n, start, end, step;
    scanf("%d", &n);
    int re_index = -n;
    int *index = (int *)calloc(n , sizeof(int));
    for (int i = 0; i < n; i++)
        *(index + i) = re_index++;

    int *arr = (int *)malloc(n * sizeof(int));
    for(int i=0; i<n; i++)
        scanf("%d", (arr + i));
    scanf("%d", &start);
    scanf("%d", &end);
    scanf("%d", &step);
        if (start < 0)
        {
            if (start < index[0])
                start = 0;
            for (int i = 0; i < n; i++)
                if (start == *(index + i))
                    start = i;
        }
        if (end < 0)
        {
            if (end < index[0])
                end = 0;
            for (int i = 0; i < n; i++)
                if (end == *(index + i))
                    end = i;
        }
    if ((start < end  && step > 0) || (start > end && step < 0))
    {
        if (start > n)
            start = n - 1;
        if (end > n)
            end = n;
        // printf("start = %d\n", start);
        // printf("end = %d\n", end);
        if (start < end  && step > 0)
            for (int i = start; i < end; i += step)
                printf("%d ", *(arr + i));
        else if (start > end && step < 0)
        {
            for (int i = (start); i > end; i += step)
                printf("%d ", *(arr + i));
        }
    }
    else
        printf("empty");
    return 0;
}