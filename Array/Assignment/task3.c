// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    scanf("%d", &rows);
    scanf("%d", &cols);
    if (rows != cols)
    {
        printf("ERROR");
        return 0;
    }

    int matrix[rows][cols], t_matrix[rows][cols];
    // Input the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int x = 0, y = 0, step = 1;
    while ( x < rows)
    {
    
        step = -step;
        x++;
    }
    return 0;
}
