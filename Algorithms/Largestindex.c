#include <stdio.h>
#include <stdlib.h>

int largestElementIndex(int *A, int start, int end)
{
    if (end == start)
    {
        return start;
    }
    int mid = (start + end) / 2;
    int l = largestElementIndex(A, start, mid);
    int r = largestElementIndex(A, mid + 1, end);
    if (A[l] >= A[r])
    {
        return l;
    }
    else
    {
        return r;
    }
}

int main()
{
    int A[] = {120, 2, 3, 4, 5, 8, 99, 6, 5, 100};
    int n = sizeof(A) / sizeof(int);
    printf("%d\n", largestElementIndex(A, 0, n - 1));
    system("pause");
    return 0;
}