#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int a[], int n)
{
    int value, next;
    for (int i = 1; i < n; i++)
    {
        value = a[i];
        next = i;
        // if previous element is larger than next element
        // shift it and put the next element in its place
        while (next > 0 && a[next - 1] > value)
        {
            a[next] = a[next - 1];
            next = next - 1;
        }
        a[next] = value;
    }
}
int main()
{
    int A[] = {2, 7, 4, 1, 5, 3, 15, 99};

    int n = sizeof(A) / sizeof(A[0]);
    InsertionSort(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
    system("pause");
    return 0;
}
