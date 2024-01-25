// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

void put_int (int num)
{
    if (num < 0)
    {
        putchar('-');
        num = -num;
    }
    if (num / 10)
        put_int(num / 10);
    putchar(num % 10 + '0');
}

void put_str(char *str)
{
    while (*str != '\0')
    {
        putchar(*str);
        str++;
    }
}

int max(int *num, int amount)
{
    int index = 0;
    for (int i = 0; i < amount; i++)
        if(*(num + index) < *(num + i))
            index = i;
    return index;
}

int min(int *num, int amount)
{
    int index = 0;
    for (int i = 0; i < amount; i++)
        if(*(num + index) > *(num + i))
            index = i;
    return index;
}

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i=0; i<n; i++)
        scanf("%d", (arr + i));
    int max_index = max(arr, n);
    int min_index = min(arr, n);
    put_int(*(arr + max_index));
    putchar(' ');
    put_int(max_index);
    putchar('\n');
    put_int(*(arr + min_index));
    putchar(' ');
    put_int(min_index);
    putchar('\n');
    
    return 0;
}