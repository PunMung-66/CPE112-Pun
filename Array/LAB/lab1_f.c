// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, c = 0;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", (a + i));
    scanf("%d", &m);
    if (m == 0 || m == 1)
        for (int i = m; i < n; i += 2) printf("%d ", *(a + i)), c++;
    if (c == 0) printf("none");
    free(a);
    return 0;
}
