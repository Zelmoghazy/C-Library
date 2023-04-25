#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a >= b) ? a : b;
}
int MaxSubarray(int A[], int start, int end, int *li, int *ri)
{
    if (start == end)
    {
        return A[start];
    }
    int mid = start + (end - start) / 2;
    int L = MaxSubarray(A, start, mid, li, ri);
    int R = MaxSubarray(A, mid + 1, end, li, ri);
    int leftsum = A[mid];
    int rightsum = A[mid + 1];
    for (int i = mid, sum = 0; i >= start; i--)
    {
        sum += A[i];
        if (sum >= leftsum)
        {
            leftsum = sum;
            (*li) = i;
        }
    }
    for (int i = mid + 1, sum = 0; i <= end; i++)
    {
        sum += A[i];
        if (sum >= rightsum)
        {
            rightsum = sum;
            (*ri) = i;
        }
    }
    if (L > (leftsum + rightsum) && L > R)
    {
        (*li) = start;
        (*ri) = mid;
    }
    if (R > (leftsum + rightsum) && R > L)
    {
        (*li) = mid + 1;
        (*ri) = end;
    }
    return max(max(L, R), leftsum + rightsum);
}

int main()
{
    int A[] = {3, -6, 8, -3, -3, 6, -3, 5, -3, 2};
    int n = sizeof(A) / sizeof(int);
    int leftindex = 0;
    int rightindex = 0;
    printf("%d\n", MaxSubarray(A, 0, n - 1, &leftindex, &rightindex));
    for (int i = leftindex; i <= rightindex; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
