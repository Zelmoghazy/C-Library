#include <stdio.h>
#include <stdlib.h>

void Merge(int *A, int *L, int nL, int *R, int nR)
{
    int i, j, k;
    i = 0; // index of L
    j = 0; // index of R
    k = 0; // index of A

    while (i < nL && j < nR) // valid index
    {
        if (L[i] < R[j]) // smallest unpicked
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while (i < nL)
    {
        A[k++] = L[i++];
    }
    while (j < nR)
    {
        A[k++] = R[j++];
    }
}

// Recursive function to sort an array of integers.
void MergeSort(int *A, int n)
{
    int mid, i, *L, *R;
    if (n < 2)
        return; // base condition. 
    //If the array has less than two element, return.

    mid = n / 2; // find the mid index.

    L = (int *)malloc(mid * sizeof(int));
    R = (int *)malloc((n - mid) * sizeof(int));

    for (i = 0; i < mid; i++)
    {
        L[i] = A[i]; // creating left subarray
    }
    for (i = mid; i < n; i++)
    {
        R[i - mid] = A[i]; // creating right subarray
    }
    // recursive call
    MergeSort(L, mid);            // sorting the left subarray
    MergeSort(R, n - mid);        // sorting the right subarray
    Merge(A, L, mid, R, n - mid); // Merging L and R into A as sorted list.
    free(L);
    free(R);
}

int main()
{

    int A[] = {2, 4, 1, 6, 8, 5, 3, 7}; // creating an array of integers.
    int i, numberOfElements;
    numberOfElements = sizeof(A) / sizeof(A[0]);

    // Calling merge sort to sort the array.
    MergeSort(A, numberOfElements);

    // printing all elements in the array once its sorted.
    for (i = 0; i < numberOfElements; i++)
    {
        printf("%d\n", A[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}