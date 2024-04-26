// Punnawat Mungkalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct edge {
    int u, v, w;
} edge;

int find(int x, int *parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void merge(int x, int y, int *parent) {
    x = find(x, parent);
    y = find(y, parent);
    if (x == y) return;
    parent[y] = x;
}

int compare(const void *a, const void *b) {
    edge *x = (edge *)a;
    edge *y = (edge *)b;
    return x->w - y->w;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    edge edges[MAX];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    
    qsort(edges, m, sizeof(edge), compare);
    
    int parent[MAX];
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    int sum = 0;
    for (int i = 0; i < m; i++) {
        if (find(edges[i].u, parent) != find(edges[i].v, parent)) {
            merge(edges[i].u, edges[i].v, parent);
            sum += edges[i].w;
        }
    }
    
    printf("%d\n", sum);
    return 0;
}
