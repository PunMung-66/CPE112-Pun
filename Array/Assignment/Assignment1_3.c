// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

void spiralOfMatrix(int enrow, int encol, int arr1[enrow][encol])
{
    int i, rowind = 0, colind = 0;

    // Loop through the matrix elements in a spiral pattern
    while (rowind < enrow && colind < encol)
    {
        // Print elements of the first row
        for (i = colind; i < encol; ++i)
        {
            printf("%d ", arr1[rowind][i]);
        }
        rowind++;

        // Print elements of the last column
        for (i = rowind; i < enrow; ++i)
        {
            printf("%d ", arr1[i][encol - 1]);
        }
        encol--;

        // Print elements of the last row if it is within matrix boundaries
        if (rowind < enrow)
        {
            for (i = encol - 1; i >= colind; --i)
            {
                printf("%d ", arr1[enrow - 1][i]);
            }
            enrow--;
        }

        // Print elements of the first column if it is within matrix boundaries
        if (colind < encol)
        {
            for (i = enrow - 1; i >= rowind; --i)
            {
                printf("%d ", arr1[i][colind]);
            }
            colind++;
        }
    }
}

int main() {
    int rows, cols;
    scanf("%d", &rows);
    scanf("%d", &cols);

    int matrix[rows][cols], t_matrix[rows][cols];
    // Input the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    spiralOfMatrix(rows, cols, matrix);
    return 0;
}
