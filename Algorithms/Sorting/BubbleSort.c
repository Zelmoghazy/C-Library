#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break; // best case if its already sorted
        }
    }
}

int main()
{
    int A[] = {2, 7, 4, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);
    BubbleSort(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
    system("pause");
    return 0;
}