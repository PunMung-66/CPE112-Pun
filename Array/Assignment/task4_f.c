// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <math.h>

int main()
{
    int row, col, row2, col2;
    scanf("%d %d", &row, &col);
    int mat1[row][col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &mat1[i][j]);

    scanf("%d %d", &row2, &col2);
        
    int mat2[row2][col2];
    for (int i = 0; i < row2; i++)
        for (int j = 0; j < col2; j++)
            scanf("%d", &mat2[i][j]);
    if (col != row2)
    {
        printf("Not Compatible");
        return (0);
    }
        int ans[row][col2];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col2; j++)
                ans[i][j] = 0;
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                for (int a = 0; a < col; a++)
                    ans[i][j] += mat1[i][a] * mat2[a][j];
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col2; j++)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
    return (0);
}