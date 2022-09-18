#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int iMin = i; // index of minimum element
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[iMin]) // any element less than current minimum
            {
                iMin = j; // update minimum element index
            }
        }
        int temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;
    }
}

int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};

    SelectionSort(A, 6);

    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", A[i]);
    }
    system("pause");
    return 0;
}