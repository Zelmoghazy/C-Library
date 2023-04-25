#include <stdio.h>
#include <stdlib.h>
int count = 0;
int BinarySearchRec(int *A, int start, int end, int value)
{
    count++;
    if (end >= start)
    {
        if (end == start)
        {
            if (value == A[end])
            {
                return end;
            }
            else
            {
                return -1;
            }
        }
        int mid = start + (end - start) / 2;
        if (value == A[mid])
        {
            return mid;
        }
        else if (value < A[mid])
        {
            return BinarySearchRec(A, start, mid - 1, value);
        }
        else if (value > A[mid])
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
    int A[50];
    for (size_t i = 0; i < 50; i++)
    {
        A[i] = i;
    }
    BinarySearchRec(A, 0, 49, 49);
    printf("%d\n", count);
    system("pause");
    return 0;
}