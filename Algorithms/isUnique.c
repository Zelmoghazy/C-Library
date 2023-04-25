#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool UniqueElements(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] == A[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 8, 1};
    if (UniqueElements(A, 8))
    {
        printf("Success\n");
    }
    system("pause");
    return 0;
}