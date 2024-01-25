#include <stdio.h>

int main()
{
    int n, step = 0, count = 0, status = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    for (int i = 0; i < n;)
    {
        step = arr[i];
        if (step == 0)
            break;
        if (i == (n-1))
        {
            status = 1;
            break;
        }
        i += step;
        count++;
    }
    if (step == 0 || status == 0)
        printf("Not Possible");
    else
        printf("%d ",count);
    return 0;
}