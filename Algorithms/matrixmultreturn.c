#include <stdio.h>
#include <stdlib.h>

int **matrix_multiplication(int **A, int **B, int r1, int c1, int r2, int c2)
{
    if (c1 != r2)
    {
        printf("Error: Incompatible matrix dimensions.\n");
        exit(1);
    }
    int **C = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++)
    {
        C[i] = (int *)malloc(c2 * sizeof(int));
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
int main()
{

    int r1 = 2, c1 = 3, r2 = 3, c2 = 2;
    int **a = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++)
    {
        a[i] = (int *)malloc(c1 * sizeof(int));
    }
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;

    int **b = (int **)malloc(r2 * sizeof(int *));
    for (int i = 0; i < r2; i++)
    {
        b[i] = (int *)malloc(c2 * sizeof(int));
    }
    b[0][0] = 7;
    b[0][1] = 8;
    b[1][0] = 9;
    b[1][1] = 10;
    b[2][0] = 11;
    b[2][1] = 12;

    int **result = matrix_multiplication(a, b, r1, c1, r2, c2);
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r1; i++)
    {
        free(a[i]);
    }
    free(a);
    for (int i = 0; i < r2; i++)
    {
        free(b[i]);
    }
    free(b);
    for (int i = 0; i < r1; i++)
    {
        free(result[i]);
    }
    free(result);

    system("pause");
    return 0;
}