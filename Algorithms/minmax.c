#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int MaxElement(int *A, int start, int end)
{
    if (end == start)
    {
        return A[start];
    }
    else if ((end - start) == 1)
    {
        if (A[start] <= A[end])
        {
            return A[end];
        }
        else
        {
            return A[start];
        }
    }
    int mid = (start + end) / 2;
    int l = MaxElement(A, start, mid);
    int r = MaxElement(A, mid + 1, end);
    return max(l, r);
}

int main()
{
    int A[] = {120, 150, 130, 155};
    int n = sizeof(A) / sizeof(int);
    printf("%d\n", MaxElement(A, 0, n - 1));
    system("pause");
    return 0;
}