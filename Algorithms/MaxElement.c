#include <stdio.h>
#include <stdlib.h>

int MaxElement(int A[], int n)
{
    int MaxValue = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > MaxValue)
        {
            MaxValue = A[i];
        }
    }
    return MaxValue;
}

int main()
{
    int A[10] = {111, 5, 8, 9, 6, 21, 2, 1, 8, 100};
    printf("%d\n", MaxElement(A, 10));
    system("pause");
    return 0;
}