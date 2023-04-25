#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Partition(int *A, int n)
{
    int i = 0;
    int j = 0;
    int k = n - 1;
    while (j <= k)
    {
        if (A[j] < 0)
        {
            swap(&A[i++], &A[j++]);
        }
        else if (A[j] == 0)
        {
            j++;
        }
        else
        {
            swap(&A[j], &A[k--]);
        }
    }
}

int main()
{
    int A[] = {-5, 5, 2, 3, 6, 9, -8, -11, -2, -13, 0, 15};
    int n = sizeof(A) / sizeof(int);
    Partition(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}