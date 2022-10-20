#include <stdio.h>
#include <stdlib.h>

int BinarySearchRec(int *A, int start, int end, int value)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (value == A[mid])
        {
            return mid;
        }
        else if (value < A[mid])
        {
            return BinarySearchRec(A, start, mid - 1, value);
        }
        else
        {
            return BinarySearchRec(A, mid + 1, end, value);
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    int A[] = {2, 6, 13, 21, 36, 47, 63, 81, 97};
    int n = sizeof(A) / sizeof(int);
    printf("%d\n", BinarySearchRec(A, 0, n, 63));
    system("pause");
    return 0;
}