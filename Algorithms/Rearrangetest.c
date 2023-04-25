#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Rearrange(int *A, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] == 0 && A[j + 1] < 0)
            {
                swap(&A[j], &A[j + 1]);
            }
            else if (A[j] > 0 && A[j + 1] == 0)
            {
                swap(&A[j], &A[j + 1]);
            }
            else if (A[j] > 0 && A[j + 1] < 0)
            {
                swap(&A[j], &A[j + 1]);
            }
        }
    }
}

int main()
{
    int A[] = {-5, 5, 2, 3, 6, 9, -8, -11, -2, -13, 0, 15};
    int n = (sizeof(A) / sizeof(int));
    Rearrange(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}