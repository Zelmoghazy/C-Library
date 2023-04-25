#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
count = 0;

int BinarySearch(int const *A, int n, int value, bool first)
{
    int start = 0;
    int end = n - 1;
    int result = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (A[mid] == value)
        {
            result = mid;
            if (first)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (value < A[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}

int Count(int const *A, int n, int value)
{
    int firstIndex = BinarySearch(A, n, value, true);
    int lastIndex = BinarySearch(A, n, value, false);
    return lastIndex - firstIndex + 1;
}
int main()
{
    int A[] = {1, 1, 3, 3, 5, 5, 5, 5, 5, 9, 9, 11};
    int n = sizeof(A) / sizeof(int);
    printf("%d\n", BinarySearch(A, n, 25, false));
    printf("%d\n", Count(A, n, 5));
    system("pause");
    return 0;
}