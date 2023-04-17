#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void AllPermutations(int arr[], int start, int N)
{
    if (start == N - 1)
    {

        for (int i = 0; i < N; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i < N; i++)
    {
        swap(arr, start, i);
        if (((start != 1 && arr[start] != 3) ||
             (start == 1 && arr[start] == 3)))
        {
            AllPermutations(arr, start + 1, N);
        }
        swap(arr, start, i);
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(int);
    AllPermutations(array, 0, n);
    system("pause");
    return 0;
}
