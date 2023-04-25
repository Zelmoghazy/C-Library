#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int const *A, int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int A[] = {2, 13, 36, 81, 2, 21, 47, 63, 97};
    int n = sizeof(A) / sizeof(int);
    printf("%d\n", LinearSearch(A, n, 97));
    system("pause");
    return 0;
}