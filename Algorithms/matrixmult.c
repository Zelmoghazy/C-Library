#include <stdio.h>
#include <stdlib.h>

#define R1 2
#define C1 3
#define R2 3
#define C2 2

void matrixmult(int A[R1][C1], int B[R2][C2], int C[R1][C2])
{
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < R2; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


int main()
{
    int A[R1][C1] = {{1, 2, 3},
                     {4, 5, 6}};
    int B[R2][C2] = {{10, 11},
                     {20, 21},
                     {30, 31}};
    int C[R1][C2];
    matrixmult(A, B, C);

    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}