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
bool isValid(const int *A, int n)
{
    int height = (int)sqrt(n);
    int expected = n * (n + 1) / (2 * (int)sqrt(n));
    // rows
    for (int i = 0; i < n; i = i + height)
    {
        int sum = 0;
        for (int j = i; j < i + height; j++)
        {
            sum += A[j];
        }
        if (sum != expected)
        {
            return false;
        }
    }
    // columns
    for (int i = 0; i < height; i++)
    {
        int sum = 0;
        for (int j = i; j <= i + (height - 1) * height; j = j + height)
        {
            sum += A[j];
        }
        if (sum != expected)
        {
            return false;
        }
    }
    // Diagonals
    int sum = 0;
    for (int i = 0; i < height; i++)
    {
        sum += A[i * height + i];
    }
    if (sum != expected)
    {
        return false;
    }
    sum = 0;
    for (int i = 0; i < height; i++)
    {
        sum += A[height - 1 + i * (height - 1)];
    }
    if (sum != expected)
    {
        return false;
    }
    return true;
}

void AllPermutations(int arr[], int start, int N, int Constant)
{
    if (start == N - 1)
    {
        if (isValid(arr, N))
        {
            for (int i = 0; i < N; i++)
            {
                if (i % ((int)sqrt(N)) == 0 && i != 0)
                {
                    printf("\n");
                }
                printf("%d ", arr[i]);
            }
            printf("\n");
            printf("\n");
        }
        return;
    }
    for (int i = start; i < N; i++)
    {
        swap(arr, start, i);
        if (((start != N / 2 && arr[start] != Constant) ||
             (start == N / 2 && arr[start] == Constant)))
        {
            AllPermutations(arr, start + 1, N, Constant);
        }
        swap(arr, start, i);
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(array) / sizeof(int);
    int constant = ((int)sqrt(n) * (int)sqrt(n) + 1) / 2;
    AllPermutations(array, 0, n, constant);
    system("pause");
    return 0;
}
