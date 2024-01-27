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

    // Dynamically allocate memory for a 2D array
    int **matrix = (int **)calloc(rows, sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)calloc(cols, sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed\n");

            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]); // Example: Sequential values
        }
    }
    
    int pri = 0, sec = 0;

    for (int i = 0; i < rows; i++) {
        pri += matrix[i][i];
        sec += matrix[i][rows - i - 1];
    }

    printf("Primary: %d\n", pri);
    printf("Secondary: %d\n", sec);
    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
