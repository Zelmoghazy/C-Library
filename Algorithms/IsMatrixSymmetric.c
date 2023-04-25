#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define N 3

bool isSymmetric(int Matrix[N][N], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (Matrix[i][j] != Matrix[j][i])
                return false;
    return true;
}

int main()
{
    int mat[N][N] = {{3, 5, 8},
                     {3, 4, 7},
                     {8, 5, 3}};
    if (isSymmetric(mat, 3))
        printf("Yes\n");
    else
        printf("No\n");
    system("pause");
    return 0;
}