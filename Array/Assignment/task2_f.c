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
    //Transpose the matrix
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) 
            t_matrix[j][i] = matrix[i][j];
    // check if the matrix is symmetric
    int sym = 1, skew = 1;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] != t_matrix[i][j]) 
                sym = 0;
            if (matrix[i][j] != -t_matrix[i][j] && i != j)
                skew = 0;
        }
    if (sym == 1)
        printf("The matrix is symmetric");
    else if (skew == 1)
        printf("The matrix is skew-symmetric");
    else
        printf("None");
    return 0;
}
