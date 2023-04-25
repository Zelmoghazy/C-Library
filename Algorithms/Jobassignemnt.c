#include <stdio.h>
#include <stdlib.h>

#define N 4
int MinimumCost = INT_MAX;

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void FindMinimumCost(int A[], int CM[][N], int start, int n)
{
    if (start == n - 1)
    {
        int cost = 0;
        for (int i = 0; i < n; i++)
        {
            cost += CM[A[i]][i];
        }
        if (cost < MinimumCost)
        {
            MinimumCost = cost;
        }
        return;
    }
    for (int i = start; i < n; i++)
    {
        swap(A, start, i);
        FindMinimumCost(A, CM, start + 1, n);
        swap(A, start, i);
    }
}

int main()
{
    int array[N] = {1, 2, 3, 4};
    int CostMatrix[][N] = {{9, 2, 7, 8},
                           {6, 4, 3, 7},
                           {5, 8, 1, 8},
                           {7, 6, 9, 4}};
    FindMinimumCost(array, CostMatrix, 0, N);
    printf("%d\n", MinimumCost);
    system("pause");
    return 0;
}
